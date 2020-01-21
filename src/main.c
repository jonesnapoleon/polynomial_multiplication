#include <stdio.h>
#include <time.h>
#include "array.h"
#include "point.h"

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
}


int main(){
    TabPOINT T, THull;
    BacaIsiTabPOINT(&T);
    printf("===============\n");
    // uncomment below to show the randomized input array of points.
    // printf("=====================================================================================================================================\nKondisi Awal\n");
    TulisIsiTabPOINT(T);
    // printf("\n=====================================================================================================================================\n");
    float start = clock();
    MakeEmpty(&THull, Neff(T) * 2 + 3);
    int iTHull = IdxMin;
    for(int i = IdxMin; i <= Neff(T); i ++){
        for(int j = i; j <= Neff(T); j ++){
            if(i != j){
                if(Determinasi(T, i, j)){
                    Neff(THull) += 2;
                    Absis(Elmt(THull, iTHull)) = Absis(Elmt(T, i));
                    Ordinat(Elmt(THull, iTHull)) = Ordinat(Elmt(T, i));
                    Absis(Elmt(THull, iTHull + 1)) = Absis(Elmt(T, j));
                    Ordinat(Elmt(THull, iTHull + 1)) = Ordinat(Elmt(T, j));
                    iTHull += 2;
                }
            }
        }
    }
    float end = clock();
    // printf("\n=====================================================================================================================================\n");
    // printf("Before finalize, take two points each from the array below and make a line. Things are gonna be awesome.\n");
    // TulisIsiTabPOINT(THull);
    // printf("\n=====================================================================================================================================\n");
    printf("\n===============");
    Singelisasi(&THull);
    printf("\nOnly-points result output\n");
    TulisIsiTabPOINT(THull);
    printf("\n===============");
    // printf("\n=====================================================================================================================================");
    printf("\nProgram were running for %.3f miliseconds", ((float)end - start));
    printf(" specifically for the convex-hull algorithm,");
    printf(" and regardless of the console logging system.\n");
    // printf("=====================================================================================================================================\n");
    return 0;
}



