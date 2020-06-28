#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
int qS, qF;
int i, j;

int left[100000];
int log[100000][3];

vector <pair<pair<int, int>, int> > v;

int main(void){
    scanf("%d %d", &N, &Q);

    for(i = 1; i <= N; i++){
        scanf("%d %d %d", &log[i][0], &log[i][1], &log[i][2]);
        v.push_back(make_pair(make_pair(log[i][0], log[i][1]), i));
    }

    sort(v.begin(), v.end());

    int curr = v[0].second;
    int root = curr;
    int right = v[0].first.second;
    left[curr] = curr;

    for(i = 1; i < N; i++){
        curr = v[i].second;

        if(log[curr][0] <= right){
            left[curr] = root;
            
            if(right < log[curr][1]){
                right = log[curr][1];
            }
        }
        else{
            left[curr] = curr;
            root = curr;
            right = log[curr][1];
        }
    }

    for(i = 0; i < Q; i++){
        scanf("%d %d", &qS, &qF);

        if(left[qS] == left[qF]){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }

    return 0;
}