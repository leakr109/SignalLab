#include "quantizer.h"
#include <cmath>

Quantizer::Quantizer(int n, double min, double max){
    bits = n;
    minVal = min;
    maxVal = max;
    step = (max - min) / (pow(2, n) - 1);
}

vector<double> Quantizer::quantize(vector<double>& input){
    int n = input.size();
    vector<double> output(n);

    for(int i = 0; i < n; i++){
        int index = round((input[i] - minVal) / step);
        double q = minVal + index * step;
        output[i] = q;
    }
    return output;
}