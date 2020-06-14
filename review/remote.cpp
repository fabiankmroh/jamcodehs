#include <stdio.h>

using namespace std;

int st, dt;
int min = 1000;

void remote(int cnt, int temp){
    if(cnt > 5){
        return;
    }
    if(temp == dt){
        if(cnt < min)
            min = cnt;
        return;
    }

    remote(cnt+1, temp+1);
    remote(cnt+1, temp+5);
    remote(cnt+1, temp+10);

    remote(cnt+1, temp-1);
    remote(cnt+1, temp-5);
    remote(cnt+1, temp-10);
}

int main(void){
    scanf("%d %d", &st, &dt);

    remote(0, st);
    printf("%d\n", min);

    return 0;
}