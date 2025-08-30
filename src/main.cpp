#include <iostream>
using namespace std;

#include "generator.h"
#include "quantizer.h"

int main() {
    //generate
    SignalGenerator gen(10.0, 1.0, 0.0, 100.0, 20);
    vector<double> signal = gen.generate();
    for (double x : signal) {
        cout << x << '\n';
    }
    cout << "------------\n";

    //quantize
    Quantizer q(3, -1, 1);
    vector<double> quantSignal = q.quantize(signal);
    for (double x : quantSignal) {
        cout << x << '\n';
    }

    return 0;
}