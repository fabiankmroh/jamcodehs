#include <stdio.h>
#include <algorithm>

using namespace std;

int minCnt[100001] = { 0, };

int getMinCnt(int n){
    minCnt[1] = 0;

    for(int i = 2; i <= n; i++){
        minCnt[i] = minCnt[i-1] + 1;

        if(i % 3 == 0){
            minCnt[i] = min(minCnt[i], minCnt[i/3]+1);
        }
        else if(i % 2 == 0){
            minCnt[i] = min(minCnt[i], minCnt[i/2]+1);
        }
    }

    return minCnt[n];
}

int main(void){
    int n;
    scanf("%d", &n);

    printf("%d\n", getMinCnt(n));

    return 0;
}