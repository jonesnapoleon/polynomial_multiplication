#include "array.h"
#include <stdio.h>

TabFLOAT Shift(TabFLOAT F, int shift){
  TabFLOAT X;
  MakeEmpty(&X, Degree(F) + shift + 5);
  Degree(X) =  Degree(F) + shift;
  Clear(&X);
  for(int i = IdxMin; i <= Degree(X); i ++){
    if(i >= shift){
      Elmt(X, i) = Elmt(F, i - shift);
    }
  }
  return X;
}

TabFLOAT AddTwo(TabFLOAT A, TabFLOAT B, int *countAddDivideConquer, int *countMultipleDivideConquer){
  TabFLOAT X;
  MakeEmpty(&X, Degree(B) + 5);
  Degree(X) =  Degree(B);
  Clear(&X);
  for(int i = IdxMin; i <= Degree(A); i ++){
    Elmt(X, i) = Elmt(A, i) + Elmt(B, i);
    *countAddDivideConquer = *countAddDivideConquer + 1;
  }
  for(int i = Degree(A) + 1; i <= Degree(B); i ++){
    Elmt(X, i) = Elmt(B, i);
    *countAddDivideConquer = *countAddDivideConquer + 1;
  }
  return X;
}

TabFLOAT AddThree(TabFLOAT A, TabFLOAT B, TabFLOAT C, int *countAddDivideConquer, int *countMultipleDivideConquer){
  TabFLOAT X;
  MakeEmpty(&X, Degree(C) + 5);
  Degree(X) =  Degree(C);
  Clear(&X);
  for(int i = IdxMin; i <= Degree(A); i ++){
    Elmt(X, i) = Elmt(A, i) + Elmt(B, i) + Elmt(C, i);
    *countAddDivideConquer = *countAddDivideConquer + 1;
  }
  for(int i = Degree(A) + 1; i <= Degree(B); i ++){
    Elmt(X, i) = Elmt(B, i) + Elmt(C, i);
    *countAddDivideConquer = *countAddDivideConquer + 1;
  }
  for(int i = Degree(B) + 1; i <= Degree(C); i ++){
    Elmt(X, i) = Elmt(C, i);
    *countAddDivideConquer = *countAddDivideConquer + 1;
  }
  return X;
}

TabFLOAT MinusThree(TabFLOAT A, TabFLOAT B, TabFLOAT C, int *countAddDivideConquer, int *countMultipleDivideConquer){
  TabFLOAT X;
  MakeEmpty(&X, Degree(A) + 5);
  Degree(X) =  Degree(A);
  Clear(&X);
  for(int i = IdxMin; i <= Degree(B); i ++){
    Elmt(X, i) = Elmt(A, i) - Elmt(B, i) - Elmt(C, i);
    *countAddDivideConquer = *countAddDivideConquer + 1;
  }
  for(int i = Degree(B) + 1; i <= Degree(C); i ++){
    Elmt(X, i) = Elmt(A, i) - Elmt(C, i);
    *countAddDivideConquer = *countAddDivideConquer + 1;
  }
  for(int i = Degree(C) + 1; i <= Degree(A); i ++){
    Elmt(X, i) = Elmt(A, i);
    *countAddDivideConquer = *countAddDivideConquer + 1;
  }
  return X;
}

void DivideTwo(TabFLOAT *F, TabFLOAT *Z1, TabFLOAT *Z2){
  
  MakeEmpty(Z1, (Degree(*F) - 1) / 2 + 5);
  Degree(*Z1) = Degree(*F) / 2 - 1;
  Clear(Z1);

  MakeEmpty(Z2, Degree(*F) - Degree(*Z1) + 5);
  Degree(*Z2) = Degree(*F) - Degree(*F) / 2;
  Clear(Z2);
    
  for(int i = IdxMin; i <= Degree(*Z1); i ++){
    Elmt(*Z1, i) = Elmt(*F, i);
  }
  
  int countZ2 = 0;
  
  for(int i = Degree(*Z1) + 1; i <= Degree(*F); i ++){
    Elmt(*Z2, countZ2) = Elmt(*F, i);
    countZ2 ++;
  }

}

TabFLOAT Divide(TabFLOAT *A, TabFLOAT *B, int *countAddDivideConquer, int *countMultipleDivideConquer){
  TabFLOAT D;
  MakeEmpty(&D, Degree(*A) + Degree(*B) + 5);
  Degree(D) = Degree(*A) + Degree(*B);
  Clear(&D);

  if(Degree(*A) <= 1 && Degree(*B) <= 1){
    Elmt(D, 0) = Elmt(*A, 0) * Elmt(*B, 0);
    Elmt(D, 1) = Elmt(*A, 0) * Elmt(*B, 1) + Elmt(*A, 1) * Elmt(*B, 0);
    Elmt(D, 2) = Elmt(*A, 1) * Elmt(*B, 1);
    *countAddDivideConquer = *countAddDivideConquer + 1;
    *countMultipleDivideConquer = *countMultipleDivideConquer + 4;
    return D;
  }

  else {
    TabFLOAT Z1, Z2, Z3, Z4;
    TabFLOAT DC1, DC2, DC21, DC22, DC3;
    
    DivideTwo(A, &Z1, &Z2);
    DivideTwo(B, &Z3, &Z4);
    
    int fullDegree = (Degree(*A) / 2 ) * 2;
    int halfDegree = Degree(*A) / 2;

    DC1 = Divide(&Z1, &Z3, countAddDivideConquer, countMultipleDivideConquer);
    DC3 = Divide(&Z2, &Z4, countAddDivideConquer, countMultipleDivideConquer);
    DC21 = AddTwo(Z1, Z2, countAddDivideConquer, countMultipleDivideConquer);
    DC22 = AddTwo(Z3, Z4, countAddDivideConquer, countMultipleDivideConquer);
    DC2 = MinusThree(Divide(&DC21, &DC22, countAddDivideConquer, countMultipleDivideConquer), DC1, DC3, countAddDivideConquer, countMultipleDivideConquer);
    
    return AddThree( DC1, Shift(DC2, halfDegree), Shift(DC3, fullDegree), countAddDivideConquer, countMultipleDivideConquer);
  }

}

void DivideConquer(TabFLOAT *D, TabFLOAT *A, TabFLOAT *B ,int *countAddDivideConquer, int *countMultipleDivideConquer){
  *countMultipleDivideConquer = 0;
  *countAddDivideConquer = 0;
  *D = Divide(A, B, countAddDivideConquer, countMultipleDivideConquer);
}
