#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int, pair<int, int> > > v;

int N, i;
int r1pos, r2pos;
int s, e, l;
int ans = 100000000;
int visited[100001];
int loc[100001];

void solve(int cPos, int dist, int longest){
    if(visited[cPos] == 1){
        return;
    }

    visited[cPos] = 1;

    if(cPos == r2pos){
        printf("%d\n", dist-longest);
        return;
    }

    int cur = loc[cPos];

    while(v[cur].first == cPos){
        if(longest > v[cur].second.first){
            solve(v[cur].second.second, dist+v[cur].second.first, longest);
        }
        else{
            solve(v[cur].second.second, dist+v[cur].second.first, v[cur].second.first);
        }
        cur++;        
        if(cur == v.size()){
            break;
        }
    }
}

int main(void){
    scanf("%d %d %d", &N, &r1pos, &r2pos);

    for(i = 0; i < N-1; i++){
        scanf("%d %d %d", &s, &e, &l);

        v.push_back(make_pair(s, make_pair(l, e)));
        v.push_back(make_pair(e, make_pair(l, s)));
    }

    sort(v.begin(), v.end());
    
    for(i = 0; i < v.size(); i++){
        if(i == 0){
            loc[v[i].first] = 0;
        }
        
        if(v[i-1].first != v[i].first){
            loc[v[i].first] = i;
        }
    }

    solve(r1pos, 0, 0);

    return 0;
}