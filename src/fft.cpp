#include "fft.h"
#include <complex>
#include <cmath>

#define PI 3.1415926535897932384626433832

vector<complex<double>> PKE (int n){
    vector<complex<double>> pke(n);
    for(int i = 0; i < n; i++){
        pke[i] = complex<double>(cos(2*PI*i/n), sin(2*PI*i/n));
    }
    return pke;
}

void konjugiraj(vector<complex<double>>& p, int n){
    for(int i = 0; i < n; i++){
        p[i] = conj(p[i]);
    }
}

vector<complex<double>> fft (vector<complex<double>>& p, int n){
    if(n <= 1){
        return p;
    }

    //razdelis polinom na sode in lihe k
    vector<complex<double>> sodi;
    vector<complex<double>> lihi;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            sodi.push_back(p[i]);
        }else{
            lihi.push_back(p[i]);
        }
    }

    //izracunas vrednosti na vsaki polovici
    vector<complex<double>> vsodi = fft(sodi, n/2);
    vector<complex<double>> vlihi = fft(lihi, n/2);
    
    //sestavis vrednostno predstavitev
    vector<complex<double>> pke = PKE(n);
    vector<complex<double>> rezultat(n);
    for(int i = 0; i < n/2; i++){
        rezultat[i] = vsodi[i] + pke[i] * vlihi[i];
        rezultat[i + n/2] = vsodi[i] - pke[i] * vlihi[i];
    }
    return rezultat;
}

vector<complex<double>> ifft (vector<complex<double>>& p, int n){
    konjugiraj(p,n);
    vector<complex<double>> res = fft(p,n);
    konjugiraj(res,n);

    //delimo z n
    for(int i = 0; i < n; i++){
        res[i] /= n;
    }
    return res;
}

int potenca2(int x){
    for(int i = 1; true; i *= 2){
        if(x <= i){
            return i;
        }
    }
    return 0;
}

int fastFurierTransform(vector<double>& signal){
    int nx = signal.size();
    int n = potenca2(nx*2);
    vector<complex<double>> p(n);

    for(int i = 0; i < nx; i++) p[i] = complex<double>(signal[i], 0.0);
    for(int i = nx; i < n; i++) p[i] = complex<double>(0.0, 0.0);

    vector<complex<double>> res = fft(p,n);    //dobim vrednostno predstavitev
    //ifft(res, n);

    return 0;
}
