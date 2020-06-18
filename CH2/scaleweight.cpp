#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <math.h>

using namespace std;

int userinput;
int ans[7];
int p[7] = {1,3,9,27,81,243,729};
int l[7];
int r[7];

void display(){
    int i;

    printf("%d ", userinput);
    for(i = 0; i < 7; i++){
        if(ans[i] == 1){
            printf("%d ", p[i]);
        }
    }    

    printf("0 ");

    for(i = 0; i < 7; i++){
        if(ans[i] == 2){
            printf("%d ", p[i]);
        }
    }

    printf("\n");
    return;
}

void scale(int l, int r, int wN){
    if(l == r){
        display();
        return;
    }

    if(wN == 7) return;

    ans[wN] = 1;
    scale(l + p[wN], r, wN+1);

    ans[wN] = 2;
    scale(l, r + p[wN], wN+1);

    ans[wN] = 0;
    scale(l, r, wN+1);

}

int main(void){
    scanf("%d", &userinput);
    scale(userinput, 0, 0);
    return 0;
}