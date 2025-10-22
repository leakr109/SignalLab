#include "generator.h"
#include <cmath> 
#include <fstream>
#define _USE_MATH_DEFINES


SignalGenerator::SignalGenerator(double fs, int n): samplingFrequency(fs), numSamples(n), signal(n, 0.0) {
    // clear sinusoid.csv file
    ofstream clearFile("../visualization/sinusoids.csv", ios::trunc);
    clearFile.close();
}

// generates a sampled cosine wave signal & saves it to visualization/sinusoids.csv
void SignalGenerator::add(double F, double A, double ph){
    vector<double> sinusoid(numSamples);

    for(int i = 0; i < numSamples; i++){
        double t = i / samplingFrequency;
        sinusoid[i] = A * cos(2 * M_PI* F * t + ph);  //ce generiras sin, pride pri faznem spektru do zamika faze pi/2 -> fft: realna komponenta je kosinus
        signal[i] += sinusoid[i];
    }

    // save
    ofstream file("../visualization/sinusoids.csv", ios::app);  //mode: append to the file
    for(int i = 0; i < numSamples; i++){
        file << sinusoid[i];
        if(i < numSamples - 1) file << ',';
    }
    file << '\n';
    file.close();
}

// returns finished signal and saves it to visualization/signal.csv
vector<double> SignalGenerator::get(){
    ofstream file("../visualization/signal.csv");

    for (int i = 0; i < numSamples; i++){
        file << signal[i];
        if(i < numSamples - 1) file << ',';
    }
    file << '\n';
    file.close();

    return signal;
}

int SignalGenerator::getNumSamples() const {
    return numSamples;
}