#include <stdio.h>

using namespace std;

int cnt;

void stair(int lvl){
    if(lvl == 4){
        cnt++;
        return;
    }
    else if(lvl > 4){
        return;
    }
    
    stair(lvl+1);
    stair(lvl+2);
}

int main(void){
    stair(0);

    printf("%d\n", cnt);

    return 0;
}