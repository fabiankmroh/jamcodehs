#include <stdio.h>

int fibonacciN(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibonacciN(n-1) + fibonacciN(n-2);
}

int main(void){
    int n;

    scanf("%d", &n);
    printf("%d\n", fibonacciN(n));

    return 0;
}