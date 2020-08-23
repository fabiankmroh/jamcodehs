#include <stdio.h>

using namespace std;

int N, M;
int i;
int tmp1, tmp2;
int result[100100];
int numCheck[100100];
int cnt[1000100][2];

int main(void){
	scanf("%d %d", &N, &M);

    for(i = 1; i <= M; i++){
        scanf("%d %d", &tmp1, &tmp2);

        cnt[tmp1][0]++;
        cnt[tmp2][1]++;
    }

    // Rear
    for(i = 1; i <= N; i++){
        result[i]+=cnt[i][0];
    }

    // Front
    for(i = 1; i <= N; i++){
        result[i] += (i - cnt[i][1]);
    }          

    // Check Up
    for(i = 1; i <= N; i++){
        if(numCheck[result[i]] == 0)
            numCheck[result[i]]++;
        else{
            printf("-1\n");
            return 0;
        }
    }

    for(i = 1; i <= N; i++){
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}