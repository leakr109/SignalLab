#ifndef QUANTIZER_H
#define QUANTIZER_H

#include <vector>
using namespace std;

class Quantizer {
private:
    int bits;
    double minVal;
    double maxVal;
    double step;

public:
    Quantizer(int n, double min, double max);
    vector<double> quantize(vector<double>& input);
};

#endif 