#include <stdio.h>

int cnt;
int n;

void stair(int lvl){
    if(lvl == n){
        cnt++;
        return;
    }
    if(lvl % 4 == 0 && lvl != 0){
        return;
    }
    else if(lvl > n){
        return;
    }

    stair(lvl+3);
    stair(lvl+5);
}

int main(void){
    scanf("%d", &n);
    
    stair(0);
    printf("%d\n", cnt);
}