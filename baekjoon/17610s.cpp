#include <stdio.h>
#define MIDDLE  260000

using namespace std;

int weight[13];
int possible[5200002] = { 0, };
int i, j;
int k, ans = 0;
int sum = 0;

void print(void){
    for(i = 1; i <= sum; i++){
        printf("possible[%d] = %d\n", i, possible[i+sum]);
    }
    printf("\n\n");

    return;
}

void makeOne(int n){
    for(j = MIDDLE-sum; j <= MIDDLE+sum; j++){
        if(possible[j] < n && possible[j] > 0){
            possible[j+weight[n]] = n;
            printf("possible[%d] = %d\n", j+weight[n], n);

            possible[j-weight[n]] = n;
            printf("possible[%d] = %d\n", j-weight[n], n);
        }
    }
    printf("\n");
    print();

    return;
}

int main(void){
    scanf("%d", &k);

    for(i = 0; i < k; i++){
        scanf("%d", &weight[i]);
        sum += weight[i];
    }
    
    possible[weight[0]+sum] = 1;
    printf("possible[%d] = %d\n", weight[0], 1);

    possible[weight[0]-weight[1]+sum] = 1;
    printf("possible[%d] = %d\n", weight[0]-weight[1], 1);

    possible[weight[0]+weight[1]+sum] = 1;
    printf("possible[%d] = %d\n", weight[0]+weight[1], 1);

    printf("\n\n");

    print();

    for(i = 2; i < k; i++){
        printf("makeOne(%d)\n", i);
        makeOne(i);
    }

    for(i = 1; i <= sum; i++){
        if(possible[i] == 0)
            ans++;
    }

    printf("%d\n", ans);
}