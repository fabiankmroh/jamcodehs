#include <stdio.h>

int qLoc[9];
int userinput;
int cnt = 0;

void queen(int x, int y){
    int i, j;
    qLoc[x] = y;

    if(x == userinput-1){
        cnt++;
        return;
    }

    for(i = 0; i < userinput; i++){
        int status = 1;

        for(j = 0; j <= x; j++){
            if(qLoc[j] == i){
                status = 0;
            }

            if(qLoc[j]+j == x+1+i){
                status = 0;
            }

            if(j-qLoc[j] == x+1-i){
                status = 0; 
            }
        }

        if(status == 1) queen(x+1, i);
    }

    return;
}

int main(void){
    scanf("%d", &userinput);

    for(int k = 0; k < userinput; k++){
        queen(0,k);
    }

    printf("%d\n", cnt);
    return 0;
}