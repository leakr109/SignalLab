#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
using namespace std;

class SignalGenerator {
private:
    double samplingFrequency;
    int numSamples;
    vector<double> signal;

public:
    SignalGenerator(double fs, int n);
    void add(double F, double A, double ph);
    vector<double> get();
    int getNumSamples() const;
};

#endif 