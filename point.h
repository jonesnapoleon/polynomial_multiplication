#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct {
	float X;
	float Y;
} POINT;

typedef struct {
	POINT P1;
	POINT P2;
} GARIS;

#define Ordinat(P) (P).Y
#define Absis(P) (P).X

POINT MakePOINT (float X, float Y);
void BacaPOINT (POINT * P, int max);
void TulisPOINT (POINT P);
float Gradien (POINT P1, POINT P2);

#endif