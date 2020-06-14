#include <stdio.h>

using namespace std;

int cnt;

void chair(int color, int total){
    if(total == 3){
        if(color == 2)
            cnt++;
        return;
    }

    chair(color+1, total+1);
    chair(color, total+1);
}

int main(void){
    chair(0,0);

    printf("%d\n", cnt);

    return 0;
}