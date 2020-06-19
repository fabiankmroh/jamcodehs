#include <stdio.h>

int coins[100];

int AllCase(int value, int index){
    if(value == 0){
        return 1;
    }
    else if(index == 0){
        if(value % coins[index] == 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    int cnt = 0;
    int coinCnt = value / coins[index];

    for(int i = 0; i <= coinCnt; i++){
        cnt += AllCase(value-coins[index]*i, index-1);
    }

    return cnt;
}

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%d", &coins[i]);
    }

    printf("%d", AllCase(k, n-1));

    return 0;
}