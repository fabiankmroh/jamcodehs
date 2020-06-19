#include <stdio.h>

using namespace std;

int coins[100];
int changeCase[10001];

int AllCases(int k, int n){
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(j >= coins[i]){
                changeCase[j] = changeCase[j] + changeCase[j - coins[i]];
            }
        }
    }

    return changeCase[k];
}

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%d", &coins[i]);
    }

    for(int i = 0; i <= k; i++){
        if(i % coins[0] == 0) {
            changeCase[i] = 1;
        }
    }

    printf("%d", AllCases(k, n));
    
    return 0;
}