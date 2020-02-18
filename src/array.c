#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

void MakeEmpty(TabFLOAT *T, int maxel){
  TI(*T) = (float *) malloc((maxel+ 1) * sizeof(float));
  MaxEl(*T) = maxel;
  Neff(*T) = 0;
}

void BacaIsi(TabFLOAT *T){
  int N;
  printf("Input polinom degree: ");
  scanf("%d", &N);
  MakeEmpty(T, N + 3);
  Neff(*T) = N;
  srand(time(0));
  for(int i = IdxMin; i <= Neff(*T); i++){
    float value = rand() % 100;
    float sign = rand() % 2;
    if(sign == 1){
      Elmt(*T, i) = value * -1;
    }
    else {
      Elmt(*T, i) = value;
    }
  }
}

void TulisIsi(TabFLOAT T){
  for(int i = Neff(T); i >= IdxMin; i --) {
    if(i == Neff(T)){
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
  for(int i = IdxMin; i <= Neff(*C); i ++){
    Elmt(*C, i) = 0;
  }
}

void BruteForce(TabFLOAT *C, TabFLOAT *A, TabFLOAT *B){
  for(int a = IdxMin; a <= Neff(*A); a ++){
    for(int b = IdxMin; b <= Neff(*B); b ++){
      Elmt(*C, a + b) += Elmt(*A, a) * Elmt(*B, b);
    }
  }
}

void DivideConquer(TabFLOAT *C, TabFLOAT *A, TabFLOAT *B){
  
}