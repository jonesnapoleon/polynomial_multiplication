#ifndef ARRAYDIN_H
#define ARRAYDIN_H

#include "boolean.h"
#include "point.h"

#define IdxMin 1
#define IdxUndef -999

typedef int IdxType;
typedef struct {
  POINT *TI;
  int Neff;
  int MaxEl;
} TabPOINT;

typedef struct {
  boolean *TI;
  int Neff;
  int MaxEl;
} TabBool;

#define Neff(T) (T).Neff
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxEl(T) (T).MaxEl

void MakeEmpty(TabPOINT *T, int maxel);
void BacaIsiTabPOINT(TabPOINT *T);
void TulisIsiTabPOINT(TabPOINT T);

boolean Determinasi(TabPOINT T, int a, int b);

#endif