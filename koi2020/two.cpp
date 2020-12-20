#include <stdio.h>

using namespace std;
int info[15][5];
int sum[5];
int chosen[15] = {0, };
int require[4];
int N, i, j, minprice;

int check(int p, int f, int c, int v){
    if(p < require[0] || f < require[1] || c < require[2] || v < require[3])
        return 0;
    return 1;
}

void solve(int n, int protein, int fat, int carbo, int vita, int price){
    if(n > N){
        return; 
    }
    if(check(protein, fat, carbo, vita)){
        if(price < minprice){
            minprice = price;
        }

        printf("\nMinprice switched\n");
        printf("Minprice: %d\n", minprice);

        for(i = 0; i < 15; i++){
            if(chosen[i] == 1)
                printf("%d ", i+1);
        }
        printf("\n");

        return; 
    }

    chosen[n] = 1;
    protein += info[n][0];
    fat += info[n][1];
    carbo += info[n][2];
    vita += info[n][3];
    price += info[n][4];

    solve(n+1, protein, fat, carbo, vita, price);
    solve(n+2, protein, fat, carbo, vita, price);
}

int main(void){
    scanf("%d", &N);

    for(i = 0; i < 4; i++){
        scanf("%d", &require[i]);
    }
    
    for(i = 0; i < N; i++){
        for(j = 0; j < 5; j++){
            scanf("%d", &info[i][j]);
            sum[j] += info[i][j];
        }
    }

    if(sum[0] < require[0] || sum[1] < require[1] || sum[2] < require[2] || sum[3] < require[3]){
        printf("-1\n");
        return 0;
    }
    
    minprice = sum[4];

    solve(0,0,0,0,0,0);
    
    printf("%d\n", minprice);
    return 0;
}