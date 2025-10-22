#include "generator.h"
#include "quantizer.h"
#include "fft.h"
#include "spectrum.h"
#include <cstdlib>

#include <iostream>
using namespace std;

int fs = 1024;  //število vzorvec na sekundo

bool checkNyquist(double F){
    if (!(fs >= 2 * F)){
        cout << "Nyquist condition is NOT met" << '\n';
        return false;
    }
    return true;
}

int main() { 
    int N = 1024;  // N = fs/F*k

    cout << "Num of sinusoids: ";
    int n; cin >> n;
    cout << '\n';

    //generate
    SignalGenerator gen(fs, N);
    for(int i = 0; i < n; i++){
        cout << "sinusoid " << i + 1<< " (frequency amplitude phase): ";
        double f, a, ph;
        cin >> f >> a >> ph;
        if(!checkNyquist(f)) return 1;
        gen.add(f, a, ph);
    }
    vector<double> signal = gen.get();  

    //quantize
    Quantizer q(8, -3, 3);          //bits, minVal, maxVal
    vector<double> quantSignal = q.quantize(signal);

    //perform fft and get amplitude and phase spectrum
    vector<complex<double>> frequencyDomain_signal = fastFurierTransform(signal);
    if(saveSpectrum(frequencyDomain_signal, fs, N)){
        return 1;
    }

    //spectrum visualization
    system("python3 ../visualization/graph.py");

    return 0;
}