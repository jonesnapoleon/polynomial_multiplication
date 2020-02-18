#include <stdio.h>
#include <time.h>
#include "array.h"

int main(){
  TabFLOAT A, B, C;
  printf("Polinom pertama\n"); Spread;
  BacaIsi(&A);
  TulisIsi(A); Spread; Nl;
  printf("Polinom kedua\n"); Spread;
  BacaIsi(&B);
  TulisIsi(B); Spread; Nl;
  float start = clock();
  MakeEmpty(&C, Neff(A) + Neff(B) + 5);
  Neff(C) = Neff(A) + Neff(B);
  Clear(&C);
  BruteForce(&C, &A, &B);
  // DivideConquer(&C, &A, &B);

  printf("Hasil kali kedua polinom\n"); Spread;
  TulisIsi(C); Spread; Nl;
  float end = clock();
  printf("Program were running for %.3f miliseconds", ((float)end - start));
  return 0;
}



