#include <stdio.h>
#define DEBUG   1

int round;
int caseN;
int i, tmp1, tmp2;

int solve(int yh, int ds){
    if(yh > ds){
        if(DEBUG)
            printf("YH is larger\n");
        int curRN = yh;
        int remain = round-curRN+1;
        
        if(ds + remain < yh)
            return 0;
        // 0 3 같은 케이스 구현
        else
            return 1;
    }

    else if(yh == ds){
        if(DEBUG)
            printf("Samsam\n");
        return 1;
    }

    else{
        if(DEBUG)
            printf("DS is larger\n");
        int curRN = ds;
        int remain = round-curRN;

        if(yh + remain < ds)
            return 0;
       // 0 3 같은 케이스 구현 
        else
            return 1;
    }
}

int main(void){
    scanf("%d", &round);
    scanf("%d", &caseN);

    for(i = 0; i < caseN; i++){
        scanf("%d %d", &tmp1, &tmp2);

        printf("%d\n", solve(tmp1, tmp2));
    }

    return 0;
}