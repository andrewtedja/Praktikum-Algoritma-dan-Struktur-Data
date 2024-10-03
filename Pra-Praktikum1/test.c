#include <stdio.h>
#include <math.h>
#include "complex.h"

boolean IsCOMPLEXValid(float Re, float Im) {
    return true;
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
    Real(*C) = Re;
    Imag(*C) = Im;
}

void BacaCOMPLEX(COMPLEX *C) {
    float Re, Im;
    scanf("%f %f", &Re, &Im);
    CreateComplex(C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C); {
    if (Imag(C) > 0) {
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