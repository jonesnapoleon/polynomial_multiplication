#include <stdio.h>
#include "point.h"
#include "math.h"

POINT MakePOINT (float X, float Y){
    POINT koordinat;
    Absis(koordinat) = X;
    Ordinat(koordinat) = Y;
    return koordinat;
} 

void BacaPOINT (POINT * P){
    float x, y;
    scanf("%f %f", &x, &y);
    *P = MakePOINT(x, y);
}

void TulisPOINT (POINT P){
    printf("(%.2f, %.2f)", Absis(P), Ordinat(P));
}

float Gradien (POINT P1, POINT P2){
    if(Absis(P1) == Absis(P2)){
        return 9999;
    }
    return ( Ordinat(P2) - Ordinat(P1) ) /( Absis(P2) - Absis(P1) );
}

