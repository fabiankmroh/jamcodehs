#include <stdio.h>
#define MIDDLE  260000
#define DEBUG   1

using namespace std;

int weight[13];
int possible[5200002] = { 0, };
int i, j;
int k, ans = 0;
int sum = 0;

void print(void){
    for(i = -sum; i <= sum; i++){
        printf("possible[%d] = %d\n", i, possible[i+MIDDLE]);
    }
    printf("\n\n");

    return;
}

void makeOne(int n){
    possible[weight[n]+MIDDLE] = n;
    possible[MIDDLE-weight[n]] = n;

    for(j = MIDDLE-sum; j <= MIDDLE+sum; j++){
        if(possible[j] < n && possible[j] > 0){
            if(possible[j+weight[n]] == 0)
                possible[j+weight[n]] = n;
            if(DEBUG)
                printf("possible[%d+%d] = %d\n", j-MIDDLE, weight[n], n);

            possible[j-weight[n]] = n;
            if(DEBUG)
                printf("possible[%d-%d] = %d\n", j-MIDDLE, weight[n], n);
        }
    }
    if(DEBUG){
        printf("\n");
        print();
    }

    return;
}

int main(void){
    scanf("%d", &k);

    for(i = 0; i < k; i++){
        scanf("%d", &weight[i]);
        sum += weight[i];
    }
    
    possible[weight[0]+MIDDLE] = 1;
    possible[MIDDLE-weight[0]] = 1;

    if(DEBUG){
        printf("possible[%d] = %d\n", weight[0], 1);
        printf("possible[%d] = %d\n", -weight[0], 1);
        printf("\n\n");
    }

    possible[weight[1]+MIDDLE] = 1;
    possible[MIDDLE-weight[1]] = 1;

    if(DEBUG){
        printf("possible[%d] = %d\n", weight[1], 1);
        printf("possible[%d] = %d\n", -weight[1], 1);
    }

    possible[weight[0]-weight[1]+MIDDLE] = 1;
    possible[weight[0]+weight[1]+MIDDLE] = 1;

    if(DEBUG){
        printf("possible[%d] = %d\n", weight[0]-weight[1], 1);
        printf("possible[%d] = %d\n", weight[0]+weight[1], 1);
    }

    possible[MIDDLE-weight[0]-weight[1]] = 1;
    possible[MIDDLE-weight[0]+weight[1]] = 1;

    if(DEBUG){
        printf("possible[%d] = %d\n", MIDDLE-weight[0]-weight[1], 1);
        printf("possible[%d] = %d\n", MIDDLE-weight[0]+weight[1], 1);
        printf("\n\n");
        print();
    }

    for(i = 2; i < k; i++){
        if(DEBUG)
            printf("makeOne(%d)\n", i);
        makeOne(i);
    }

    for(i = 1; i <= sum; i++){
        if(possible[i+MIDDLE] == 0)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}