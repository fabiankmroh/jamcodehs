#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int, pair<int, int> > > pipes;

int holes, i;
int rob1pos, rob2pos;
int s, e, l;
int ans = 100000000;
int visited[100001];
int loc[100001];

void solve(int cPos, int dist, int far){
    if(visited[cPos] == 1){
        return;
    }

    visited[cPos] = 1;

    if(cPos == rob2pos){
        printf("%d\n", dist-far);
        return;
    }

    int cur = loc[cPos];

    while(pipes[cur].first == cPos){
        if(far > pipes[cur].second.first){
            solve(pipes[cur].second.second, dist+pipes[cur].second.first, far);
        }
        else{
            solve(pipes[cur].second.second, dist+pipes[cur].second.first, pipes[cur].second.first);
        }
        cur++;        
        if(cur == pipes.size()){
            break;
        }
    }
}

int main(void){
    scanf("%d %d %d", &holes, &rob1pos, &rob2pos);

    for(i = 0; i < holes-1; i++){
        scanf("%d %d %d", &s, &e, &l);

        pipes.push_back(make_pair(s, make_pair(l, e)));
        pipes.push_back(make_pair(e, make_pair(l, s)));
    }

    sort(pipes.begin(), pipes.end());
    
    for(i = 0; i < pipes.size(); i++){
        if(i == 0){
            loc[pipes[i].first] = 0;
        }
        
        if(pipes[i-1].first != pipes[i].first){
            loc[pipes[i].first] = i;
        }
    }

    solve(rob1pos, 0, 0);

    return 0;
}