#include "point.h"
#include "circle.h"
#include "boolean.h"
#include "math.h"
#include <stdio.h>

boolean IsCIRCLEValid(float X, float Y, float R){
    return (R > 0);
}

void CreateCIRCLE(CIRCLE *C, float X, float Y, float R){
    if (R > 0){
    Absis(Center(*C)) = X;
    Ordinat(Center(*C)) = Y;
    Radius(*C) = R;
    } 
}

void ReadCIRCLE(CIRCLE *C){
    float X, Y, R;
    scanf("%f %f %f", &X, &Y, &R);
    while (R<=0){
        printf("CIRCLE tidak valid\n");
        scanf("%f %f %f", &X, &Y, &R);
    }
    CreateCIRCLE(C, X, Y, R);
}

void WriteCIRCLE(CIRCLE C){
    printf("P(%.2f,%.2f) r=%.2f", Absis(Center(C)), Ordinat(Center(C)), Radius(C));
}

float Circumference(CIRCLE C){
    return (2 * 3.14 * Radius(C));
}

float Area(CIRCLE C){
    return (3.14 * Radius(C) * Radius(C));
}

// float Panjang (POINT P1, POINT P2);
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P){
    return (Panjang(Center(C), P) < Radius(C));
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P){
    return (Panjang(Center(C), P) - Radius(C) < 0.00001);  
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2){
    return ((Panjang(Center(C1), Center(C2))) < fabs(Radius(C1) - Radius(C2)));
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2){
    float d;
    d = Panjang(Center(C1), Center(C2));
    return ((d == Radius(C1) + Radius(C2)) || (d == fabs(Radius(C1) - Radius(C2))));    
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2){
    float PQ;
    PQ = Panjang(Center(C1), Center(C2));
    return ((fabs(Radius(C1) - Radius(C2))) < PQ) && (PQ < (Radius(C1) + Radius(C2)));
}