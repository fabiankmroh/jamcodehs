#include <stdio.h>
#include <stdlib.h>

using namespace std;
int possible[2600001] = { 0, };
int numOfWeight, sum = 0;
int ans = 0;
int weight[13];

void solve(int left, int right, int n){
    possible[abs(left-right)] = 1;

    if(n == numOfWeight)
        return;
    
    solve(left+weight[n], right, n+1);
    solve(left, right+weight[n], n+1);
    solve(left, right, n+1);
}

int main(void){
    int i, j;
    scanf("%d", &numOfWeight);

    for(i = 0; i < numOfWeight; i++){
        scanf("%d", &weight[i]);
        sum += weight[i];
    }

    solve(0, 0, 0);

    for(i = 1; i <= sum; i++){
        if(possible[i] == 0)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}