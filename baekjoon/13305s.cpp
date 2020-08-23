#include <stdio.h>

using namespace std;

long long int price[100005];
long long int dist[100005];
long long int total[100005];
int N, i;

int main(void){
    scanf("%d", &N);

    for(i = 0; i < N-1; i++){
        scanf("%lld", &dist[i]);
    }

    for(i = 0; i < N; i++){
        scanf("%lld", &price[i]);
    }

    total[0] = price[0] * dist[0];
    int min = price[0];

    for(i = 0; i < N; i++){
        if(price[i] < min){
            min = price[i];
        }
        total[i] = total[i-1] + min*dist[i];
    }

    printf("%lld\n", total[N-1]);
}