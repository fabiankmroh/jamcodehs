#include <stdio.h>

int a, c;
int cnt;

void chair(int color, int total){
    if(total == a){
        if(color == c){
            cnt++;
        }
        return;
    }

    chair(color+1, total+1); /* Color the next chair */
    chair(color, total+1); /* Do not color the next chair */
}

int main(void){
    scanf("%d %d", &a, &c);

    chair(0,0);
    printf("%d\n", cnt);
}