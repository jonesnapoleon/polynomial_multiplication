#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main(){
    char a,b;
    float x,y;
    int N;
    scanf("%d", &N);
    srand(time(0));
    for(int i = 0; i <= N; i++){
        x = rand( ) % 100;
        y = rand( ) % 100;
        printf("%.1f - %.1f\n", x, y);
    }
}