#include <stdio.h>
#include <algorithm>

using namespace std;

int stairs[301] = { 0, };

int maxScore(int lvl){
    if(lvl > 0){
        int oneDown, twoDown; // Max Score Attained from 1 or 2 lvls down

        oneDown = maxScore(lvl-3) + stairs[lvl-1]; // 1 -> 1 (X) 2 -> 1 (O)
        twoDown = maxScore(lvl-2);

        return max(oneDown, twoDown) + stairs[lvl]; // Return the maximum value
    }
    // else
    return 0;
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