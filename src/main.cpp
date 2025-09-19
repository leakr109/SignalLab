#include "generator.h"
#include "quantizer.h"
#include "fft.h"
#include "spectrum.h"
#include <cstdlib>

#include <iostream>
using namespace std;


int main() {
    double fs = 1024.0;   //število vzorvec na sekundo
    int N = 1024;         // N = fs/F*k
    double F = 20.0;

    //check Nyquist condition
    if (!(fs >= 2 * F)){
        cout << "Nyquist condition is NOT met" << '\n';
        return 1;
    }

    //generate
    SignalGenerator gen(fs, N);     // fs, n
    gen.add(F, 1.0, 0);             //F, A, ph
    gen.add(100, 1.0, 0); 
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