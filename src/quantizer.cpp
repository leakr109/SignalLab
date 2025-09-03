#include "quantizer.h"
#include <cmath>


Quantizer::Quantizer(int n, double min, double max){
    bits = n;
    minVal = min;
    maxVal = max;
    step = (max - min) / (pow(2, n) - 1);
}

// Returns a vector containing the quantized signal using uniform quantization
vector<double> Quantizer::quantize(vector<double>& input){
    int n = input.size();
    vector<double> output(n);

    for(int i = 0; i < n; i++){
        int index = round((input[i] - minVal) / step);  //rounds to the nearest level
        double q = minVal + index * step;
        output[i] = q;
    }
    return output;
}