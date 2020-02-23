#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bruteforce.h"
#include "divideandconquer.h"
#include "array.h"

int main(){
  time_t t;
  clock_t startBruteforce, endBruteforce, startDivideConquer, endDivideConquer;
  srand((unsigned)time(&t));

  TabFLOAT A, B, C, D; int N;
  printf("Input polinom degree: ");
  scanf("%d", &N);
  
  printf("Polinom pertama\n"); Spread;
  BacaIsi(&A, N);
  TulisIsi(A); Spread; Nl;
  
  printf("Polinom kedua\n"); Spread;
  BacaIsi(&B, N);
  TulisIsi(B); Spread; Nl;

  // START BRUTEFORCE PROCESS
  startBruteforce = clock();
  int countAddBruteforce, countMultipleBruteforce;
  MakeEmpty(&C, Degree(A) + Degree(B) + 5);
  Degree(C) = Degree(A) + Degree(B);
  Clear(&C);
  BruteForce(&C, &A, &B, &countAddBruteforce, &countMultipleBruteforce);
  endBruteforce = clock();

  // START DIVIDE AND CONQUER PROCESS
  startDivideConquer = clock();
  int countAddDivideConquer, countMultipleDivideConquer;
  MakeEmpty(&D, Degree(A) + Degree(B) + 5);
  Degree(D) = Degree(A) + Degree(B);
  Clear(&D);
  DivideConquer(&D, &A, &B, &countAddDivideConquer, &countMultipleDivideConquer);
  endDivideConquer = clock();

  printf("Hasil kali kedua polinom secara bruteforce\n"); Spread;
  printf("Jumlah pertambahan elemen di perkalian kedua polinom secara Bruteforce: %d\n", countAddBruteforce);
  printf("Jumlah perkalian elemen di perkalian kedua polinom secara Bruteforce: %d\n", countMultipleBruteforce); Spread;
  TulisIsi(C); Spread; Nl;
  
  printf("Hasil kali kedua polinom secara divide and conquer\n"); Spread;
  printf("Jumlah pertambahan elemen di perkalian kedua polinom secara DivideConquer: %d\n", countAddDivideConquer);
  printf("Jumlah perkalian elemen di perkalian kedua polinom secara DivideConquer: %d\n", countMultipleDivideConquer); Spread;
  TulisIsi(D); Spread; Nl;

  printf("Bruteforce program was running for %.3f miliseconds\n", ((float)endBruteforce - startBruteforce));
  printf("Divide and Conquer program was running for %.3f miliseconds\n", ((float)endDivideConquer - startDivideConquer));
  
  return 0;
}



