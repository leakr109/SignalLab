#include <iostream>
using namespace std;

#include "generator.h"

int main() {
    SignalGenerator gen(10.0, 1.0, 0.0, 100.0, 20);

    vector<double> signal = gen.generate();

    for (double x : signal) {
        cout << x << '\n';
    }
    return 0;
}