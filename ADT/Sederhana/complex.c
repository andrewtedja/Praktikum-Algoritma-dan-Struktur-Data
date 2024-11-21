#include "complex.h"
#include <stdio.h>

boolean IsCOMPLEXValid(float Re, float Im) {
    return true; 
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
    Real(*C) = Re;
    Imag(*C) = Im;
}

void BacaCOMPLEX(COMPLEX *C) {
    float re, im;
    scanf("%f %f", &re, &im);
    CreateComplex(C, re, im);
}

void TulisCOMPLEX(COMPLEX C) {
    if (Imag(C) >= 0) {
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    } else {
        printf("%.2f-%.2fi\n", Real(C), -Imag(C));
    }
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX result;
    CreateComplex(&result, Real(C1) + Real(C2), Imag(C1) + Imag(C2));
    return result;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX result;
    CreateComplex(&result, Real(C1) - Real(C2), Imag(C1) - Imag(C2));
    return result;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX result;
    float re = Real(C1) * Real(C2) - Imag(C1) * Imag(C2);
    float im = Real(C1) * Imag(C2) + Imag(C1) * Real(C2);
    CreateComplex(&result, re, im);
    return result;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX result;
    float denominator = Real(C2) * Real(C2) + Imag(C2) * Imag(C2);
    if (denominator == 0) {
        CreateComplex(&result, 0, 0);
    } else {
        float re = (Real(C1) * Real(C2) + Imag(C1) * Imag(C2)) / denominator;
        float im = (Imag(C1) * Real(C2) - Real(C1) * Imag(C2)) / denominator;
        CreateComplex(&result, re, im);
    }
    return result;
}

float AbsCOMPLEX(COMPLEX C) {
    return sqrt(Real(C) * Real(C) + Imag(C) * Imag(C));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C) {
    COMPLEX result;
    CreateComplex(&result, Real(C), -Imag(C));
    return result;
}

boolean CEQ(COMPLEX C1, COMPLEX C2) {
    return (Real(C1) == Real(C2)) && (Imag(C1) == Imag(C2));
}

boolean CNEQ(COMPLEX C1, COMPLEX C2) {
    return !CEQ(C1, C2);
}