#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void MakeEmpty(TabFLOAT *T, int maxel){
  TI(*T) = (float *) malloc((maxel+ 1) * sizeof(float));
  MaxEl(*T) = maxel;
  Degree(*T) = 0;
}

void BacaIsi(TabFLOAT *T, int N){
  MakeEmpty(T, N + 3);
  Degree(*T) = N;
  for(int i = IdxMin; i <= Degree(*T); i++){
    float value = rand() % 100;
    float sign = rand() % 100;
    if(sign == 1){
      Elmt(*T, i) = value * -1;
    }
    else {
      Elmt(*T, i) = value;
    }
  }
}

void TulisIsi(TabFLOAT T){
  for(int i = Degree(T); i >= IdxMin; i --) {
    if(i == Degree(T) && i != IdxMin){
      if(Elmt(T, i) < 0){
        printf("- %.1f x^%d", Elmt(T, i) * -1, i);
      }
      if(Elmt(T, i) > 0){
        printf("%.1f x^%d", Elmt(T, i), i);
      }
    }
    else if(i == IdxMin){
      if(Elmt(T, i) < 0){
        printf(" - %.1f", Elmt(T, i) * -1);
      }
      if(Elmt(T, i) > 0){
        printf(" + %.1f", Elmt(T, i));
      }
    }
    else {
      if(Elmt(T, i) < 0){
        printf(" - %.1f x^%d", Elmt(T, i) * -1, i);
      }
      else if(Elmt(T, i) == 1){
        printf(" + x^%d", i);
      }
      else if(Elmt(T, i) > 1){
        printf(" + %.1f x^%d", Elmt(T, i), i);
      }
    }
  }
  printf("\n");
}

void Clear(TabFLOAT *C){
  for(int i = IdxMin; i <= Degree(*C); i ++){
    Elmt(*C, i) = 0;
  }
}



