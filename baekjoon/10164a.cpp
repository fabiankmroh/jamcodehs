#include <stdio.h>
#include <cstring>

using namespace std;

int n, m, k;
int a[16][16];
int d[16][16];

int main(){
    scanf("%d %d %d", &n, &m, &k);

    if(k!=0) {
        int mid_i, mid_j;

        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                count++;
                if (count == k) {
                    mid_i = i;
                    mid_j = j;
                }
            }
        }

        d[1][1] = 1;
        for (int i = 1; i <= mid_i; i++) {
            for (int j = 1; j <= mid_j; j++) {
                if (i == 1 && j == 1) continue;
                d[i][j] = d[i - 1][j] + d[i][j - 1];
            }
        }

        int mid_result = d[mid_i][mid_j];

        memset(d, 0, sizeof(d));

        d[mid_i][mid_j] = 1;
        for (int i = mid_i; i <= n; i++) {
            for (int j = mid_j; j <= m; j++) {
                if (i == mid_i && j == mid_j) continue;

                d[i][j] = d[i - 1][j] + d[i][j - 1];
            }
        }
        printf("%d\n", mid_result * d[n][m]);
    }

    else{
        d[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) 
                    continue;
                d[i][j] = d[i - 1][j] + d[i][j - 1];
            }
        }
        printf("%d\n", d[n][m]);
    }
}
