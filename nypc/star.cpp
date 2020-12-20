#include <stdio.h>

int standard[3][3];
int one, two, three;
int i;

void star(int min, int sec, int mil){
    int total = min*10000 + sec*100 + mil;

    if(three >= total){
        printf("***\n");
        return;
    }
    if(two >= total && total > three){
        printf("**\n");
        return;
    }
    if(one >= total && total > two){
        printf("*\n");
        return;
    }
    if(total > one){
        printf(":(\n");
        return;
    }
}

int main(void){
    for(i = 0; i < 3; i++){
        scanf("%d:%d:%d", &standard[i][0], &standard[i][1], &standard[i][2]);
    }

    one = standard[0][0]*10000 + standard[0][1]*100 + standard[0][2];
    two = standard[1][0]*10000 + standard[1][1]*100 + standard[1][2];
    three = standard[2][0]*10000 + standard[2][1]*100 + standard[2][2];


    int attempt;
    scanf("%d", &attempt);

    int a, b, c;

    for(i = 0; i < attempt; i++){
        scanf("%d:%d:%d", &a, &b, &c);
        star(a, b, c);
    }
    
    return 0;
}