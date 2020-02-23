#ifndef DIVIDEANDCONQUER_H
#define DIVIDEANDCONQUER_H

#include "array.h"

void DivideConquer(TabFLOAT *D, TabFLOAT *A, TabFLOAT *B, int *countAddDivideConquer, int *countMultipleDivideConquer);
TabFLOAT Divide(TabFLOAT *A, TabFLOAT *B, int *countAddDivideConquer, int *countMultipleDivideConquer);

void DivideTwo(TabFLOAT *A, TabFLOAT *Z1, TabFLOAT *Z2);
TabFLOAT Shift(TabFLOAT F, int shift);

TabFLOAT MinusThree(TabFLOAT A, TabFLOAT B, TabFLOAT C, int *countAddDivideConquer, int *countMultipleDivideConquer);
TabFLOAT AddTwo(TabFLOAT A, TabFLOAT B, int *countAddDivideConquer, int *countMultipleDivideConquer);
TabFLOAT AddThree(TabFLOAT A, TabFLOAT B, TabFLOAT C, int *countAddDivideConquer, int *countMultipleDivideConquer);

#endif