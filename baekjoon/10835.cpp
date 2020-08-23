#include <stdio.h>

using namespace std;

int left[2000];
int right[2000];
int N;
int maxS = 0;
int i;

void card(int l, int r, int score){
    if(l == N || r == N){
        if(score > maxS)
            maxS = score;
        
        return;
    }

    // Rule #1
    card(l+1, r, score);
    card(l+1, r+1, score);

    // Rule #2
    if(left[l] > right[r]){
        card(l, r+1, score+right[r]);
    }
}

int main(void){
    scanf("%d", &N);
    
    for(i = 0; i < N; i++){
        scanf("%d", &left[i]);
    }

    for(i = 0; i < N; i++){
        scanf("%d", &right[i]);
    }

    card(0,0,0);

    printf("%d\n", maxS);
}