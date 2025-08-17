#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
using namespace std;

class SignalGenerator {
private:
    double frequency;
    double amplitude;
    double phase;
    double samplingFrequency;
    int numSamples;

public:
    SignalGenerator(double f, double a, double p, double fs, int n);
    vector<double> generate();
    int getNumSamples() const;
};

#endif 