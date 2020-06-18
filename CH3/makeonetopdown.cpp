#include <stdio.h>
#include <algorithm>

using namespace std;

int minCnt[100001] = { 0, };

int getMinCnt(int n){
    if(n == 1)
        return 0;
    
    if(minCnt[n] > 0)
        return minCnt[n];
    
    minCnt[n] = getMinCnt(n-1)+1;

    if(n % 3 == 0)
        minCnt[n] = min(minCnt[n], getMinCnt(n/3)+1);
    
    else if(n % 2 == 0)
        minCnt[n] = min(minCnt[n], getMinCnt(n/2)+1);

    return minCnt[n];
}

int main(void){
    int n;
    scanf("%d", &n);

    printf("%d", getMinCnt(n));

    return 0;
}