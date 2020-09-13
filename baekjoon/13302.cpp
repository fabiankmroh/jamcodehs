#include <stdio.h>

int N, M, i, tmp;
int day[105];
int minprice;

void solve(int date, int coupon, int price){
    if(date >= N){
        if(minprice > price){
            minprice = price;
        }

        return;
    }
    if(coupon >= 3){
        solve(date+1, coupon-3, price);
    }
    if(day[date+1]){
        solve(date+1, coupon, price);
    }

    solve(date+1, coupon, price+10000);
    solve(date+3, coupon+1, price+25000); 
    solve(date+5, coupon+2, price+37000);
}

int main(void){
    scanf("%d %d", &N, &M);

    minprice = N * 10000;

    for(i = 1; i <= M; i++){
       scanf("%d", &tmp);

       day[tmp] = 1;
    }

    solve(0, 0, 0);

    printf("%d\n", minprice);
}