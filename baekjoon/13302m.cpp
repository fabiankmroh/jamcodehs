#include <stdio.h>

int N, M, i, j, tmp;
int day[105];
int gagyeok[105][105];
int minprice;

void solve(int date, int coupon, int price){
    if(date > N+1){
        return;
    }
    gagyeok[date][coupon] = price;

    if(coupon >= 3 && (gagyeok[date+1][coupon-3] == 0 || price < gagyeok[date+1][coupon-3])){
        solve(date+1, coupon-3, price);
    }
    if(day[date+1] && (gagyeok[date+1][coupon] == 0 || price < gagyeok[date+1][coupon])){
        solve(date+1, coupon, price);
    }

    if(gagyeok[date+1][coupon] == 0 || price+10000 < gagyeok[date+1][coupon])
        solve(date+1, coupon, price+10000);
    if(gagyeok[date+3][coupon+1] == 0 || price+25000 < gagyeok[date+3][coupon+1])
        solve(date+3, coupon+1, price+25000); 
    if(gagyeok[date+5][coupon+2] == 0 || price+37000 < gagyeok[date+5][coupon+2])
        solve(date+5, coupon+2, price+37000);
}

int main(void){
    scanf("%d %d", &N, &M);

    if(N == M){
        printf("0\n");
        return 0;
    }

    minprice = N * 10000;

    for(i = 1; i <= M; i++){
       scanf("%d", &tmp);

       day[tmp] = 1;
    }

    solve(0, 0, 0);

    for(i = 0; i < N; i++){
        tmp = gagyeok[N][i];
        if(minprice > tmp && tmp > 0){
            minprice = tmp;
        }
    }

    printf("%d\n", minprice);
}