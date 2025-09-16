#include "spectrum.h"
#include <cmath>
#include <cstdio>

vector<double> amplitudeSpectrum(vector<complex<double>>& signal_fft, int N){
    int n = signal_fft.size();
    vector<double> amplitudes(n/2);
    for(int k = 0; k < n/2; k++){
        amplitudes[k] = abs(signal_fft[k])/N*2;
    }
    return amplitudes;
}

vector<double> phaseSpectrum(const vector<complex<double>>& signal_fft) {
    int n = signal_fft.size();
    vector<double> phases(n/2);
    for (int k = 0; k < n/2; k++) {
        phases[k] = atan2(signal_fft[k].imag(), signal_fft[k].real());  //ce generiras sinus, pristej pi/2
    }
    return phases;
}

// saves spectrum to /visualization/data.csv
int saveSpectrum(vector<complex<double>>& signal_fft, double fs, int N){
    int n = signal_fft.size();
    vector<double> amp = amplitudeSpectrum(signal_fft, N);
    vector<double> phs = phaseSpectrum(signal_fft);

    double df = fs / n; // frekvenčni korak
    
    ofstream file("../visualization/data.csv");
    if (!file.is_open()) return 1; //error

    for (int i = 0; i < amp.size(); i++){
        double f = i * df;
        file << f << "," << amp[i] << "," << phs[i] << "\n";  
    }

    file.close();
    return 0;
}


