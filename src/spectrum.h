#ifndef SPECTRUM_H
#define SPECTRUM_H

#include <vector>
#include <complex>
using namespace std;

// computes amplitude spectrum
vector<double> amplitudeSpectrum(vector<complex<double>>& signal_fft, int N);

// computes phase spectrum
vector<double> amplitudeSpectrum(vector<complex<double>>& signal_fft, int N);

// for now: finds the input frequency, amplitude and phase
void spectrum(vector<complex<double>>& signal_fft, double fs, int N);

#endif
