#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100010];
int logs[100010][3];
vector < pair <pair<int, int>, int> > v;
int N, Q;

int main(){
    scanf("%d %d", &N, &Q);

    for(int i = 1; i <= N; i++){
        scanf("%d %d %d", &logs[i][0], &logs[i][1], &logs[i][2]);
        v.push_back( make_pair( make_pair( logs[i][0],logs[i][1] ), i ) );
    }
    sort(v.begin(), v.end());

    int root = v[0].second;
    int rightmost = v[0].first.second;
    arr[v[0].second] = v[0].second;
    for(int i = 1; i < N; i++){
        int num = v[i].second;

        if(logs[num][0] <= rightmost){
            arr[num] = root;
            rightmost = rightmost < logs[num][1] ? logs[num][1]:rightmost;
        }
        else{
            arr[num] = num;
            root = num;
            rightmost = logs[num][1];
        }
    }

    for(int i = 0; i < Q; i++){
        int j, k;
        scanf("%d %d", &j, &k);
        if(arr[j] == arr[k]) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
