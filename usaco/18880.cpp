#include <stdio.h>
#include <algorithm>

using namespace std;

int stallN;
int ans = 1000005;
char arr[100005];
int prevOne = 0;
int dist[100005];
int distCnt = 0;
int i, j;

int main(void){
    scanf("%d", &stallN);

    for(i = 0; i < stallN; i++){
        scanf("%c", &arr[i]);
        if(arr[i] == '1'){
            dist[distCnt] = i - prevOne-1;
            prevOne = i;
            distCnt++;
        }
    }
    
    sort(dist, dist+distCnt);

    dist[distCnt-1]--;
    dist[distCnt-2]--;

    for(i = 0; i < distCnt; i++){
        if(ans > dist[i] && dist[i] != 0){
            ans = dist[i];
        }
    }

    printf("%d\n", ans);
    return 0;
}