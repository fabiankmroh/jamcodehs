#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector < pair<int, int> > v;

int vertex[1000005][2];
int N, i, j;
int start, finish;

void print(void){
    printf("\n\n");

    for(i = 0; i < v.size(); i++){
        printf("%d %d\n", v[i].first, v[i].second);
    }
}

int include(void){
    i = 1; // Points the tuple that needs to be checked
    int loc = v[0].second;
    int cnt = 1;

    while(i < v.size()){
        if(loc < v[i].first){
            loc = v[i].second;
            cnt++;
        }

        i++;
    }

    return cnt;
}

int included(void){ // Included by others
    int cnt = 0;

    for(i = 1; i < v.size(); i++){ // Check through one by one
        if(v[i-1].second < v[i].first || v[i].second < v[i+1].first){
            cnt++;
        }
    }

    return cnt;
}

int main(void){
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d %d", &vertex[i][0], &vertex[i][1]);
    }
    vertex[N][0] = vertex[0][0];
    vertex[N][1] = vertex[0][1];
        
    for(i = 1; i <= N; i+=2){
        if(vertex[i][0] == vertex[i+1][0] && (vertex[i][1] * vertex[i+1][1]) < 0){
            if(vertex[i][0] < vertex[i+1][0])
                v.push_back(make_pair(vertex[i][0], vertex[i+1][0]));
            else
                v.push_back(make_pair(vertex[i+1][0], vertex[i][0]));
        }
    }
    sort(v.begin(), v.end());

    if(v.size() == 1){
        printf("1 1\n");
        return 0;
    }

    printf("%d %d\n", include(), included());
    return 0;
}