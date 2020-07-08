#include <stdio.h>
#include <algorithm>

using namespace std;

vector< pair<int, int> > pipes;
int holes, i;
int rob1pos, rob2pos;
int s, e, l;

void solve(int cPos, int cost, int longest){
    
}

int main(void){
    scanf("%d %d %d", &holes, &rob1pos, &rob2pos);

    if(rob1pos == rob2pos){
        printf("0\n");
        return 0;
    }

    for(i = 0; i < holes; i++){
        scanf("%d %d %d", &s, &e, &l);
        pipes.push_back(make_pair(s, l));
        pipes.push_back(make_pair(e, l));
    }
}