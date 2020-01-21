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
  printf("======================\n");
  printf("Input number of points\n");
  printf("======================\n");
  scanf("%d", &N);
  MakeEmpty(T, N + 3);
  Neff(*T) = N;
  srand(time(0));
  for(int i = IdxMin; i <= N; i++){
    BacaPOINT(&Elmt(*T, i), 100);
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



boolean Determinasi(TabPOINT T, int a, int b){
  boolean B, state;
  float Y1 = Ordinat(Elmt(T, a)) +  Gradien(Elmt(T, b), Elmt(T, a)) 
             * ( Absis(Elmt(T, 1)) - Absis(Elmt(T, a)) );
  state = (Y1 >= Ordinat(Elmt(T, 1)));
  B = state;
  int i = 2;
  while(i <= Neff(T) && B == state){
    if(i != a && i != b){
      float Y = Ordinat(Elmt(T, a)) +  Gradien(Elmt(T, b), Elmt(T, a)) 
                * ( Absis(Elmt(T, i)) - Absis(Elmt(T, a)) );
      B = (Y >= Ordinat(Elmt(T, i)));
    }
    i ++;
  }
  return B == state;
}




// void MakeEmptyBool(TabBool *T, int maxel){
//   TI(*T) = (boolean *) malloc((maxel+ 1) * sizeof(boolean));
//   MaxEl(*T) = maxel;
//   Neff(*T) = 0;
// }

// boolean DeterminasiFinalBoolean(TabBool B){
//   boolean same = true;
//   int i = 1;
//   while(i < Neff(B) && same){
//     if(Elmt(B, i) != Elmt(B, i + 1)){
//       same = !same;
//     }
//     i ++;
//   }
//   return same;
// }

// boolean Determinasi(TabPOINT T, int a, int b){
//   TabBool B;
//   int iB = 1;
//   MakeEmptyBool(&B, Neff(T) + 3);
//   for(int i = 1; i <= Neff(T); i ++){
//     if(i != a && i != b){
//       Neff(B) ++;
//       float Y = Ordinat(Elmt(T, a)) +  Gradien(Elmt(T, b), Elmt(T, a)) * ( Absis(Elmt(T, i)) - Absis(Elmt(T, a)) );
//       Elmt(B, iB) = ( Y >= Ordinat(Elmt(T, i)) );
//       iB ++;
//     }
//   }
//   return DeterminasiFinalBoolean(B);
// }