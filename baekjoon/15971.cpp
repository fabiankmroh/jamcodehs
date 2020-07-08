#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector< pair<int, pair<int, int> > > pipes; // Hole # & Connected Pipe Length & Connected Hole #

int holes, i;
int rob1pos, rob2pos;
int s, e, l;
int ans = 100000000;

void print(void){
    printf("# of Paths: %d\n", holes-1);
    printf("# of Vector: %d\n", pipes.size());

    for(i = 0; i < 2*(holes-1); i++){
        printf("s: %d e: %d l: %d\n", pipes[i].first, pipes[i].second.second, pipes[i].second.first);
    }

    return;
}

void solve(int cPos, int pPos, int dist, int far){
    printf("solve(%d, %d, %d, %d)\n", cPos, pPos, dist, far);
    int s, l, e;
    if(cPos == rob2pos){
        printf("End case\n");
        int a = dist-far;
        printf("%d = %d-%d", a, dist, far);

        if(ans > a)
            ans = a;
        
        return;
    }
    
    for(i = 0; i < 2*(holes-1); i++){
        s = pipes[i].first;
        l = pipes[i].second.first;
        e = pipes[i].second.second;

        if(cPos == s){
            if(e != pPos){
                if(far < l)
                    far = l;

                solve(e, s, dist+l, far);
            }
            else{
                continue;
            }
        }

        if(pipes[i+1].first > cPos)
            break;
    }

    return;
}

int main(void){
    scanf("%d %d %d", &holes, &rob1pos, &rob2pos);

    if(rob1pos == rob2pos){
        printf("0\n");
        return 0;
    }

    for(i = 0; i < holes-1; i++){
        scanf("%d %d %d", &s, &e, &l);

        pipes.push_back(make_pair(s, make_pair(l,e)));
        pipes.push_back(make_pair(e, make_pair(l,s)));
    }

    sort(pipes.begin(), pipes.end());
    printf("Sort Complete\n");

    print();

    // solve(rob1pos, rob1pos, 0, 0);

    printf("ans: %d\n", ans);

    return 0;
}