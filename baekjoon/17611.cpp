#include <stdio.h>
#define ZERO    500000

int lineSE[1000000] = { 0, };
int lineCnt[1000000] = { 0, };
int x[100000][2];
int xmin = 500000;
int xmax = -500000;
int n, i;

int main(void){
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d %d", &c[i][0], &c[i][1]);

        // Min
        if(c[i][0] < xmin)
            xmin = c[i][0];
        
        // Max
        if(c[i][0] > xmax)
            xmax = c[i][0];
    }

    
}