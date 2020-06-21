#include <stdio.h>

int cnt = 0;

int SumOfDigits(int n){
    int sum = 0;

    while(n > 0){
        sum += (n % 10);
        n /= 10;
    }

    return sum;
}

int main(void){
    int input;

    scanf("%d", &input);

    for(int i = 1; i <= input; i++){
        if(i % SumOfDigits(i) == 0)
            cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}