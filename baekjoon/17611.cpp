#include <stdio.h>
#include <vector>
#include <algorithm>

#define ZERO    500000

using namespace std;

int c[100010][2];

int horizontal[1000005];
int vertical[1000005];

vector <pair<int, int> > x; // Start, End
vector <pair<int, int> > y; // Start, End

int xmin = 500000;
int xmax = -500000;

int ymin = 500000;
int ymax = -500000;

int n, i;

int main(void){
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d %d", &c[i][0], &c[i][1]);
    }

    c[n][0] = c[0][0];
    c[n][1] = c[0][1];

    for(i = 0; i < n; i++){
        if(c[i][1] == c[i+1][1]){
            if(c[i+1][0] > c[i][0])
                x.push_back(make_pair(c[i][0], c[i+1][0]));
            else
                x.push_back(make_pair(c[i+1][0], c[i][0]));
        }

        if(c[i][0] == c[i+1][0]){
            if(c[i+1][1] > c[i][1])
                y.push_back(make_pair(c[i][1], c[i+1][1]));
            else
                y.push_back(make_pair(c[i+1][1], c[i][1]));
        }
    }
    
    int l, r;

    // x
    for(i = 0; i < x.size(); i++){
        l = x[i].first + ZERO;
        r = x[i].second + ZERO;

        horizontal[l]++;
        horizontal[r]--;
    }

    // y
    for(i = 0; i < y.size(); i++){
        l = y[i].first + ZERO;
        r = y[i].second + ZERO;

        vertical[l]++;
        vertical[r]--;
    }

    int cnt = 0;
    int max = 0;

    // Check X
    for(i = 0; i < 1000005; i++){
        cnt += horizontal[i];

        if(max < cnt)
            max = cnt;
    }

    cnt = 0;

    for(i = 0; i < 1000005; i++){
        cnt += vertical[i];
        
        if(max < cnt)
            max = cnt;
    }

    printf("%d\n", max);

    return 0;
}