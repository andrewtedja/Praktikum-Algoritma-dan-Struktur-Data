#include "fraction.h"
#include <stdio.h>


int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}


boolean IsFRACTIONValid(int N, int D) {
    return D != 0;  
}


void CreateFRACTION(FRACTION *F, int N, int D) {
    if (IsFRACTIONValid(N, D)) {
        Numerator(*F) = N;
        Denominator(*F) = D;
    } else {

        Numerator(*F) = 0;
        Denominator(*F) = 1;
    }
}


void ReadFRACTION(FRACTION *F) {
    int N, D;
    do {
        scanf("%d %d", &N, &D);
        if (!IsFRACTIONValid(N, D)) {
            printf("FRACTION tidak valid\n");
        }
    } while (!IsFRACTIONValid(N, D));
    
    CreateFRACTION(F, N, D);
}

void WriteFRACTION(FRACTION F) {
    F = SimplifyFRACTION(F);
    printf("%d/%d", Numerator(F), Denominator(F));
}


FRACTION AddFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION result;
    int N = Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator(F1);
    int D = Denominator(F1) * Denominator(F2);
    CreateFRACTION(&result, N, D);
    return SimplifyFRACTION(result);
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION result;
    int N = Numerator(F1) * Denominator(F2) - Numerator(F2) * Denominator(F1);
    int D = Denominator(F1) * Denominator(F2);
    CreateFRACTION(&result, N, D);
    return SimplifyFRACTION(result);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION result;
    int N = Numerator(F1) * Numerator(F2);
    int D = Denominator(F1) * Denominator(F2);
    CreateFRACTION(&result, N, D);
    return SimplifyFRACTION(result);
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION result;
    int N = Numerator(F1) * Denominator(F2);
    int D = Denominator(F1) * Numerator(F2);
    CreateFRACTION(&result, N, D);
    return SimplifyFRACTION(result);
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F) {
    FRACTION result;
    int N = Numerator(F) * n;
    int D = Denominator(F);
    CreateFRACTION(&result, N, D);
    return SimplifyFRACTION(result);
}


FRACTION SimplifyFRACTION(FRACTION F) {
    int gcd = GCD(Numerator(F), Denominator(F));
    int N = Numerator(F) / gcd;
    int D = Denominator(F) / gcd;

    if (D < 0) { 
        N = -N;
        D = -D;
    }
    
    FRACTION simplified;
    CreateFRACTION(&simplified, N, D);
    return simplified;
}

float ToDecimal(FRACTION F) {
    return (float) Numerator(F) / (float) Denominator(F);
}