#include <stdio.h>

using namespace std;

int coins[100];
int changeCase[100001][100];

int AllCases(int value, int index){
    if(changeCase[value][index] > 0){
        return changeCase[value][index];
    }
    else if(index < 1){
        return 0;
    }

    int cnt = 0;
    int coinCnt = value / coins[index];
    int newValue;

    for(int i = 0; i <= coinCnt; i++){
        newValue = value - coins[index]*i;
        changeCase[newValue][index-i] = AllCases(newValue, index-1);
        cnt += changeCase[newValue][index-1];
    }

    return cnt;
}

int main(void){
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%d", &coins[i]);
        changeCase[0][i] = 1;
    }

    for(int i = 1; i <= k; i++){
        if(i % coins[0] == 0){
            changeCase[i][0] = 1;
        }
    }

    printf("%d", AllCases(k, n-1));

    return 0;
}