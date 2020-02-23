#ifndef ARRAYDIN_H
#define ARRAYDIN_H

#include "boolean.h"

#define Spread printf("===============\n");
#define Nl printf("\n");

#define IdxMin 0
#define IdxUndef -999

typedef struct {
  float *TI;
  int Degree;
  int MaxEl;
} TabFLOAT;


#define Degree(T) (T).Degree
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxEl(T) (T).MaxEl

void MakeEmpty(TabFLOAT *T, int maxel);
void BacaIsi(TabFLOAT *T, int degree);
void TulisIsi(TabFLOAT T);
void Clear(TabFLOAT *C);

#endif