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
    SignalGenerator gen(F, 1.0, 0, fs, N);  //F, A, ph, fs, n
    vector<double> signal = gen.generate();

    //quantize
    Quantizer q(8, -3, 3);  //bits, minVal, maxVal
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