#include <stdio.h>

int qLoc[9];
int input;
int cnt = 0;

void placeQ(int x, int y){
    int i, j;
    qLoc[x] = y;

    if(x == input-1){
        cnt++;
        return;
    }

    for(i = 0; i < input; i++){
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

        if(status == 1) placeQ(x+1, i);
    }

    return;
}

int main(void){
    scanf("%d", &input);

    for(int i = 0; i < input; i++){
        placeQ(0,i);
    }

    printf("%d\n", cnt);
    return 0;
}