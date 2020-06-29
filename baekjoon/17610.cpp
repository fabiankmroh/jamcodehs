#include <stdio.h>
#define DEBUG   1

int k, sum;
int weight[13];
int assign[13];
int available[1000] = { 0, };
int i, j;

void scale(int wT, int wN){
    if(wT < 0)
        return;
    if(wN == k-1)
        return;

    if(DEBUG)
        printf("Weight #: %d\n", wN);

    available[wT] = 1;

    assign[wN+1] = 0;
    if(DEBUG){
        printf("0 entered\n");
    }
    scale(wT, wN+1);
        
    assign[wN+1] = 1;
    if(DEBUG)
        printf("1 entered\n");
    scale(wT+weight[wN+1], wN+1);

    assign[wN+1] = 2;
    if(DEBUG)
        printf("2 entered\n");
    scale(wT-weight[wN+1], wN+1);
}

int main(void){
    scanf("%d", &k);

    for(i = 0; i < k; i++){
        scanf("%d", &weight[i]);
        sum += weight[i];
    }

    available[sum] = 1;
    
    if(DEBUG){
        printf("S = %d\n", sum);

        for(i = 0; i < k; i++){
            printf("%d ", weight[i]);
        }

        printf("\n\n");
    }
    scale(0, 0);
}