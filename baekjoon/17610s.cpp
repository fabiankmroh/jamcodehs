#include <stdio.h>
#include <vector>
#define DEBUG   1

int available[100] = { 0, };
int weight[13];
int nW, i, cnt = 0;
int sum = 0;

void createWeight(int wT, int wN){
    if(DEBUG){
        printf("createWeight(%d, %d)\n", wT, wN);
    }

    if(available[wT] == 1){
        return;
    }
    
    available[wT] = 1;
    
    if(wN == nW-1){
        if(DEBUG)
            printf("RETURN called\n");
        return;
    }
    
    createWeight(wT+weight[wN+1], wN+1);
    if(wT-weight[wN+1] > 0)
        createWeight(wT-weight[wN+1], wN+1);
    createWeight(wT, wN+1);
}

void print(void){
    for(i = 1; i <= sum; i++){
        if(available[i] == 0){
            printf("Weight: %d\n", i);
            cnt++;
        }
    }
    printf("%d\n", cnt);
}

int main(void){
    scanf("%d", &nW);
    if(DEBUG)
        printf("Number of Weights: %d\n", nW);

    for(i = 0; i < nW; i++){
        scanf("%d", &weight[i]);
        sum += weight[i];
    }

    if(DEBUG)
        printf("First function called\n");
    createWeight(0,0);
    createWeight(weight[0],0);

    if(DEBUG)
        printf("Print function called\n");
    print();
}