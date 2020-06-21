#include <stdio.h>
#include <algorithm>

using namespace std;

int stairs[301] = { 0, };
int maxS[301] = { 0, };

int maxScore(int lvl){
    maxS[1] = stairs[1];
    maxS[2] = stairs[1] + stairs[2];

    for(int i = 3; i <= lvl; i++){
        maxS[i] = max(maxS[i-3]+stairs[i-1], maxS[i-2]) + stairs[i];
    }
    return maxS[lvl];
}

int main(void){
    int destLvl;
    scanf("%d", &destLvl);
    
    for(int i = 1; i <= destLvl; i++){
        scanf("%d", &stairs[i]);
    }

    printf("%d\n", maxScore(destLvl));
    return 0;
}