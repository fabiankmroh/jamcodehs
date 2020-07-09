#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector< pair<int, pair<int, int> > > pipes; // Hole # & Connected Pipe Length & Connected Hole #

int holes, i;
int rob1pos, rob2pos;
int s, e, l;
int ans = 100000000;
int stuck[100001] = { 0, };

void print(void){
    printf("# of Paths: %d\n", holes-1);
    printf("# of Vector: %lu\n", pipes.size());

    for(i = 0; i < 2*(holes-1); i++){
        printf("s: %d e: %d l: %d\n", pipes[i].first, pipes[i].second.second, pipes[i].second.first);
    }

    return;
}

void solve(int cPos, int pPos, int dist, int far){
    int s, l, e;
    bool makhim = true;
    if(cPos == rob2pos){
        printf("End case\n");
        int a = dist-far;
        printf("%d = %d-%d\n", a, dist, far);

        if(ans > a)
            ans = a;
        
        return;
    }
    
    printf("loop in\n");
    for(i = 0; i < 2*(holes-1); i++){
        s = pipes[i].first;
        l = pipes[i].second.first;
        e = pipes[i].second.second;

        printf("%d %d %d\n", s, l, e);

        if(cPos == s){
            makhim = false;
            if(e != pPos && stuck[e] == 0){
                if(far < l)
                    far = l;

                solve(e, s, dist+l, far);
            }
            else{
                continue;
            }
        }
        
        if(makhim == true){
            stuck[i] = 1;
            return;
        }

        if(pipes[i+1].first > cPos){
            printf("solve(%d, %d, %d, %d)\n", cPos, pPos, dist, far);
            printf("i: %d\n Break\n", i);
            break;
        }
    }

    printf("No end case. Return\n");
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

    solve(rob1pos, rob1pos, 0, 0);

    printf("ans: %d\n", ans);

    return 0;
}