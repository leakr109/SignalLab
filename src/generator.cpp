#include "generator.h"
#include <cmath> 
#define _USE_MATH_DEFINES


SignalGenerator::SignalGenerator(double f, double a, double p, double fs, int n)
    : frequency(f), amplitude(a), phase(p), samplingFrequency(fs), numSamples(n) {}

// generates a sampled cosine wave signal
vector<double> SignalGenerator::generate(){
    vector<double> signal(numSamples);

    for(int i = 0; i < numSamples; i++){
        double t = i / samplingFrequency;
        signal[i] = amplitude * cos(2 * M_PI* frequency * t + phase);  //ce generiras sin, pride pri faznem spektru do zamika faze pi/2 -> fft: realna komponenta je kosinus
    }
    return signal;
}

int SignalGenerator::getNumSamples() const {
    return numSamples;
}