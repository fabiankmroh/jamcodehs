#include <stdio.h>

int coins[100];
int changeCase[10001][100];

int AllCases(int k, int n){
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(j >= coins[i])
                changeCase[j][i] = changeCase[j][i-1] + changeCase[j-coins[i]][i];
            else
                changeCase[j][i] = changeCase[j][i-1];
        }
    }

    return changeCase[k][n-1];
}

int main(void){
    int n, k;
    
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%d", &coins[i]);
        changeCase[0][i] = 1;
    }

    for(int i = 1; i <= k; i++){
        if(i % coins[0] == 0)
            changeCase[i][0] = 1;
    }

    printf("%d", AllCases(k, n));

    return 0;
}