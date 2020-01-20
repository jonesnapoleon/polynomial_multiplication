#include <stdio.h>
#include <stdlib.h>

int main(){
    char a,b;
    int x,y;
    int a[11];
    int indexa = 0;
    for(int i = 0; i <= 4; i ++){
        scanf("%c%d, %d%c", &a,&x,&y, &b);
        a[indexa] = x;
        printf("%d %d", x, y);
        return 0;
    }
}