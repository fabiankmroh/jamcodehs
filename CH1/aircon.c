#include <stdio.h>

int dt, ct;
int min = 1000;

void remote(int cnt, int temp){
    if(cnt > 10){
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
    scanf("%d %d", &ct, &dt);

    remote(0, ct);
    
    printf("%d\n", min);

    return 0;
}