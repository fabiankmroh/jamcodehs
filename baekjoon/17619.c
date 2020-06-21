#include <stdio.h>

int start[100000];
int end[100000];
int y[100000];

int n;
int q;

int Fsolve(int from, int to){
    for(int i = from; i < to; i++){
        if(end[i] < start[i+1]){
            return 0;
        }
    }
    
    return 1;
}

int Rsolve(int from, int to){
    for(int i = from; i >= to; i--){
        if(end[i] < start[i-1]){
            return 0;
        }
    }
    
    return 1;
}

int main(void){
    int i;
    int s, e;
    
    scanf("%d %d", &n, &q);

    for(i = 1; i <= n; i++){
        scanf("%d %d %d", &start[i], &end[i], &y[i]);
    }
    
    for(i = 0; i < q; i++){
        scanf("%d %d", &s, &e);

        if(s > e)
            printf("%d", Rsolve(s,e));
        else
            printf("%d", Fsolve(s,e));
    }

    return 0;
}