#include "bruteforce.h"
#include <stdio.h>

void BruteForce(TabFLOAT *C, TabFLOAT *A, TabFLOAT *B, int *countAddBruteforce, int *countMultipleBruteforce){
  *countAddBruteforce = 0;
  *countMultipleBruteforce = 0;
  for(int a = IdxMin; a <= Degree(*A); a ++){
    for(int b = IdxMin; b <= Degree(*B); b ++){
      Elmt(*C, a + b) += Elmt(*A, a) * Elmt(*B, b);
      *countAddBruteforce = *countAddBruteforce + 1;
      *countMultipleBruteforce = *countMultipleBruteforce + 1;
    }
  }
}
