#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector < pair<int, int> > v;

int a1 = 0;
int a2 = 0;

int vertex[1000000][2];
int N, i;
int start, finish;

void print(void){
    printf("\n\n");

    for(i = 0; i < v.size(); i++){
        printf("%d %d\n", v[i].first, v[i].second);
    }
}

void solve(int n){
    for(i = 0; i < v.size(); i++){
        if(v[i].first < )
    }
}

int main(void){
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d %d", &vertex[i][0], &vertex[i][1]);
    }
    vertex[N][0] = vertex[0][0];
    vertex[N][1] = vertex[0][1];
        
    for(i = 1; i <= N; i+=2){
        if(vertex[i][1] == vertex[i+1][1] && vertex[i][1] > 0 && vertex[i+1][1] > 0){
            if(vertex[i][0] < vertex[i][1])
                v.push_back(make_pair(vertex[i][0], vertex[i+1][0]));
            else
                v.push_back(make_pair(vertex[i+1][0], vertex[i][0]));
        }
    }

    print();

    sort(v.begin(), v.end());
    printf("Sort Complete\n");

    print();

    for(i = 0; i < v.size(); i++){
        solve(i);
    }

    printf("%d %d\n", a1, a2);

    return 0;
}