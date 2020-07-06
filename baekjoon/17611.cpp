#include <stdio.h>
#define ZERO    500000

int lineSE[1000000] = { 0, };
int lineCnt[1000000] = { 0, };
int x[100000][2];
int n, i;

int main(void){
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d %d", &c[i][0], &c[i][1]);
    }

    for(i = 0; i < n; i++){
        lineSE[x[i][0]]++;
        lineSE[x[i][1]]--;
    }

    
}