#include <stdio.h>

using namespace std;

int tree[1000], basA[1000];
int tN, basket;
int basNum, max;
int i, j;

int main(void){    
    scanf("%d %d", &tN, &basket);

    max = 0;
    for(i = 0; i < tN; i++){
        scanf("%d", &tree[i]);
        if(max < tree[i])
            max = tree[i];
    }

    int sum = 0;
    for(i = 1; i < max; i++){
        sum = 0;
        for(j = 0; j < tN; j++){
            int tmp = tree[j] / i;
            sum += tmp;
        }
        
        if(sum == basket)
            break;
    }
    basNum = i;

    for(i = 0; i < tN; i++){
        if(tree[i] < basNum)
            continue;

        basA[i] = basNum; 
        tree[i] -= basNum;
    }
  
    for(i = 0; i < tN; i++){
        if(tree[i] > 0){
            basA[i] 
        }
    }

    printf("%d\n", basNum);

    return 0;
}