#include <stdio.h>
#include <algorithm>

using namespace std;

int makeoneMin(int n){
    if(n == 1){
        return 0;
    }

    int cnt = makeoneMin(n-1) + 1;

    if(n % 3 == 0){
        cnt = min(cnt, makeoneMin(n/3)+1);
    }
    else if(n % 2 == 0){
        cnt = min(cnt, makeoneMin(n/2)+1);
    }

    return cnt;
}

int main(void){
    int n;
    
    scanf("%d", &n);
    printf("%d\n", makeoneMin(n));

    return 0;
}