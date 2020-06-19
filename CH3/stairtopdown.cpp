#include <stdio.h>
#include <algorithm>

using namespace std;

int stairs[301] = { 0, };
int maxScore[301] = { 0, };

int getMaxScore(int n){
    if(n > 0){
        if(maxScore[n] > 0){
            return maxScore[n];
        }

        int upOneScore, upTwoScore;
        upOneScore = getMaxScore(n-3) + stairs[n-1];
        upTwoScore = getMaxScore(n-2);
        maxScore[n] = max(upOneScore, upTwoScore) + stairs[n];

        return maxScore[n];
    }

    return 0;
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