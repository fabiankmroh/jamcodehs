#include <stdio.h>

using namespace std;
int i, K, T;
int yh, ds;

int solve(void){
    int remainder;

    if(yh > ds){
        remainder = K - (yh-1);
        if(yh - 1 <= ds + remainder)
            return 1;
        else
            return 0;        
    }

    if(yh == ds){
        return 1;
    }
    
    if(yh < ds){
        remainder = K - ds;

        if(yh + remainder >= ds - 1)
            return 1;
        else
            return 0;
    }
}

int main(void){
    scanf("%d", &K);
    scanf("%d", &T);

    for(i = 0; i < T; i++){
        scanf("%d %d", &yh, &ds);
        printf("%d\n",solve());
    }

    return 0;
}