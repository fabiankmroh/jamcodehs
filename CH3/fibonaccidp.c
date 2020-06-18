#include <stdio.h>

int fibArr[1000];

int fibonacci(int n){
    fibArr[0] = 0;
    fibArr[1] = 1;

    for(int i = 2; i <=n; i++){
        fibArr[i] = fibArr[i-1] + fibArr[i-2];
    }

    return fibArr[n];
}

int main(void){
    int n;
    
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
    
    return 0;
}