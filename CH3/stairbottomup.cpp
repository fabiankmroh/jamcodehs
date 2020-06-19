#include <stdio.h>
#include <algorithm>

using namespace std;

int stairs[301] = { 0, };
int maxScore[301] = { 0, };

int getMaxScore(int n){
    maxScore[1] = stairs[1];
    maxScore[2] = stairs[1] + stairs[2];

    for(int i = 3; i <= n; i++){
        maxScore[i] = max(maxScore[i-3] + stairs[i-1], maxScore[i-2]) + stairs[i];
    }

    return maxScore[n];
}

int main(void){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &stairs[i]);
    }

    printf("%d", getMaxScore(n));

    return 0;
}