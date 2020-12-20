#include <stdio.h>

using namespace std;

int N, M;
int grass[100000]; 
int i, j;
int min, max;
int dist;

int placeCow(int dist){
    int cow = 0;

    for(int i = 0; i < max; i+=dist){
        if(grass[i] == 1){
            cow++;
        }
        while(grass[i] != 1 && i < max){
            i++;
        }
    }

    if(cow > N)
        return 1;
    else if(cow == N)
        return 2;
    else
        return 0;
}

int main(void){
    scanf("%d %d", &N, &M);

    for(i = 0; i < M; i++){
        int start, end;
        scanf("%d %d", &start, &end);

        for(j = start; j <= end; j++){
            grass[j] = 1;
        }
    }

    min = 0;
    while(min <= max){
        dist = (min+max)/2;

        if(placeCow(dist) == 2){
            printf("%d\n", dist);
            return 0;
        }
        else if(placeCow(dist)){
            i++;
        }
        else{
            j--;
        }
    }
}