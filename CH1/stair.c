#include <stdio.h>

int cnt;
int n;

void stair(int lvl){
    if(lvl == n){
        cnt++;
        return;
    }
    else if(lvl > n){
        return;
    }

    stair(lvl+1);
    stair(lvl+2);
}

int main(void){
    scanf("%d", &n);
    
    stair(0);
    printf("%d\n", cnt);
}