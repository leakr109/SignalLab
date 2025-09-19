#include "generator.h"
#include <cmath> 
#define _USE_MATH_DEFINES


SignalGenerator::SignalGenerator(double fs, int n): samplingFrequency(fs), numSamples(n), signal(n, 0.0) {}

// generates a sampled cosine wave signal
void SignalGenerator::add(double F, double A, double ph){
    for(int i = 0; i < numSamples; i++){
        double t = i / samplingFrequency;
        signal[i] += A * cos(2 * M_PI* F * t + ph);  //ce generiras sin, pride pri faznem spektru do zamika faze pi/2 -> fft: realna komponenta je kosinus
    }
}

vector<double> SignalGenerator::get(){
    return signal;
}

int SignalGenerator::getNumSamples() const {
    return numSamples;
}