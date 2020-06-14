#include <stdio.h>

using namespace std;

int cnt, t, c;

void chair(int color, int total){
    if(total == t){
        if(color == c)
            cnt++;
        return;
    }

    chair(color+1, total+1);
    chair(color, total+1);
}

int main(void){
    scanf("%d %d", &t, &c);

    chair(0,0);

    printf("%d\n", cnt);

    return 0;
}