#include <stdio.h>
#include "array.c"
#include "point.c"

int main(){
    TabPOINT T, THull;
    BacaIsiTabPOINT(&T);
    MakeEmpty(&THull, Neff(T) * 2 + 3);
    int iTHull = 1;
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
    Singelisasi(&THull);
    TulisIsiTabPOINT(THull);
    return 0;
}
