#include <stdio.h>

int main(void){
    int map[15][15];
    int mandatory;
    int mi, mj;
    int i, j, cnt;
    int n, m;

    scanf("%d %d %d", &n, &m, &mandatory);
    printf("%d\n", mandatory);

    cnt = 1;

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            map[i][j] = cnt;

            if(cnt == mandatory){
                mi = i;
                mj = j;
            }
            
            cnt++;
        }
    }


    return 0;
}