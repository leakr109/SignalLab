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

void spectrum(vector<complex<double>>& signal_fft, double fs, int N){
    int n = signal_fft.size();
    vector<double> amp = amplitudeSpectrum(signal_fft, N);
    vector<double> phs = phaseSpectrum(signal_fft);
    int maxF = 0;

    for(int k = 0; k < n/2; k++){
        if(amp[k] > amp[maxF]){
            maxF = k;
        }
    }
    double df = fs / n;  // frekvenčni korak
    double freq = maxF * df;

    printf("f: %.2f Hz, amp: %.2f, phs: %.2f\n", freq, amp[maxF], phs[maxF]);
}


