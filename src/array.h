#ifndef ARRAYDIN_H
#define ARRAYDIN_H

#include "boolean.h"

#define Spread printf("===============\n");
#define Nl printf("\n");

#define IdxMin 0
#define IdxUndef -999

typedef int IdxType;

typedef struct {
  float *TI;
  int Neff;
  int MaxEl;
} TabFLOAT;


#define Neff(T) (T).Neff
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxEl(T) (T).MaxEl

void MakeEmpty(TabFLOAT *T, int maxel);
void BacaFLOAT(float * P, int max);
void BacaIsi(TabFLOAT *T);
void TulisIsi(TabFLOAT T);
void Clear(TabFLOAT *C);
void BruteForce(TabFLOAT *C, TabFLOAT *A, TabFLOAT *B);
void DivideConquer(TabFLOAT *C, TabFLOAT *A, TabFLOAT *B);

#endif