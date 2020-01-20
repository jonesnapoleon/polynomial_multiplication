#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include <time.h>

void MakeEmpty(TabPOINT *T, int maxel){
  TI(*T) = (POINT *) malloc((maxel+ 1) * sizeof(POINT));
  MaxEl(*T) = maxel;
  Neff(*T) = 0;
}

void BacaIsiTabPOINT(TabPOINT *T){
  int N;
  scanf("%d", &N);
  MakeEmpty(T, N + 3);
  Neff(*T) = N;
  srand(time(0));
  for(int i = IdxMin; i <= N; i++){
    BacaPOINT(&Elmt(*T, i), 50);
  }
}

void TulisIsiTabPOINT(TabPOINT T){
  printf("[");
  for(int i = IdxMin; i <= Neff(T); i ++) {
    TulisPOINT(Elmt(T, i));
    if(i != Neff(T)) {
      printf(",");
    }
  }
  printf("]");
}

void MakeEmptyBool(TabBool *T, int maxel){
  TI(*T) = (boolean *) malloc((maxel+ 1) * sizeof(boolean));
  MaxEl(*T) = maxel;
  Neff(*T) = 0;
}

boolean DeterminasiFinalBoolean(TabBool B){
  boolean same = true;
  int i = 1;
  while(i < Neff(B) && same){
    if(Elmt(B, i) != Elmt(B, i + 1)){
      same = !same;
    }
    i ++;
  }
  return same;
}

boolean Determinasi(TabPOINT T, int a, int b){
  TabBool B;
  int iB = 1;
  MakeEmptyBool(&B, Neff(T) + 3);
  for(int i = 1; i <= Neff(T); i ++){
    if(i != a && i != b){
      Neff(B) ++;
      float Y = Ordinat(Elmt(T, a)) +  Gradien(Elmt(T, b), Elmt(T, a)) * ( Absis(Elmt(T, i)) - Absis(Elmt(T, a)) );
      Elmt(B, iB) = ( Y >= Ordinat(Elmt(T, i)) );
      iB ++;
    }
  }
  return DeterminasiFinalBoolean(B);
}

void Singelisasi(TabPOINT *T){
  for(int i = 1; i <= Neff(*T); i ++){
    float X = Absis(Elmt(*T, i));
    float Y = Ordinat(Elmt(*T, i));
    for(int j = i + 1; j <= Neff(*T); j ++){
      if(X == Absis(Elmt(*T, j)) && Y == Ordinat(Elmt(*T, j))){
        Absis(Elmt(*T, j)) = Absis(Elmt(*T, Neff(*T)));
        Ordinat(Elmt(*T, j)) = Ordinat(Elmt(*T, Neff(*T)));
        Neff(*T) --;
      }
    }
  }
  float X = Absis(Elmt(*T, 1));
  float Y = Ordinat(Elmt(*T, 1));
  Neff(*T) ++;
  Absis(Elmt(*T, Neff(*T))) = X;
  Ordinat(Elmt(*T, Neff(*T))) = Y;
}