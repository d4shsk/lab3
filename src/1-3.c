#include <stdio.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} Complex;

Complex complex_add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex complex_multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex complex_pow(Complex z, int n) {
    Complex result = {1.0, 0.0};
    for (int i = 0; i < n; i++) {
        result = complex_multiply(result, z);
    }
    return result;
}

unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

Complex complex_exp(Complex z, double e) {
    Complex sum = {1.0, 0.0};
    Complex term = {1.0, 0.0}; 

    for (int n = 1; ; n++) {
        term = complex_multiply(term, z);
        term.real /= n;
        term.imag /= n;

        double m = sqrt(term.real * term.real + term.imag * term.imag);
        if (m < e) break;

        sum = complex_add(sum, term);
    }

    return sum;
}

void print_complex(Complex z) {
    printf("%.4f %+.4fi\n", z.real, z.imag);
}
int main() {

    Complex z = {4.0, 10.0};
    double e = 1e-6;

    Complex result = complex_exp(z, e);

    printf("exp(4 + 10i) ≈ ");
    print_complex(result);
    return 0;
}
