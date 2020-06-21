#include <stdio.h>
#include <time.h>

int start[100000];
int end[100000];
int y[100000];

int n;
int q;

int solve(int from, int to){
    for(int i = from; i < to; i++){
        if(end[i] < start[i+1]){
            return 0;
        }
    }
    
    return 1;
}

int main(void){
    clock_t begin = clock();
    double time = 0.0;
    int i;
    int s, e;
    
    scanf("%d %d", &n, &q);

    for(i = 1; i <= n; i++){
        scanf("%d %d %d", &start[i], &end[i], &y[i]);
    }
    
    for(i = 0; i < q; i++){
        scanf("%d %d", &s, &e);

        printf("%d", solve(s,e));
    }

    clock_t finish = clock();
    time += (double)(finish- begin) / CLOCKS_PER_SEC;

    printf("\nRun Time: %f", time);

    return 0;
}