#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
int qS, qE;
int i, j;

int arr[100001];
int log[100001][3];

vector <pair< pair< int, int >, int> > v;

int main(void){
    scanf("%d %d", &N, &Q);

    for(i = 1; i <= N; i++){
        scanf("%d %d %d", &log[i][0], &log[i][1], &log[i][2]);

        v.push_back(make_pair(make_pair(log[i][0], log[i][1]), i));
    }

    sort(v.begin(), v.end()); /* Sort the start points */

    int cN = v[0].second;
    int root = cN;
    int end = v[0].first.second;
    arr[cN] = cN;

    for(i = 1; i < N; i++){
        cN = v[i].second;

        if(log[cN][0] <= end){ /* Set up the root point & place righter end */
            arr[cN] = root;

            if(end < log[cN][1])
                end = log[cN][1];
        }
        else{ /* If unreachable */
            arr[cN] = cN;
            root = cN;
            end = log[cN][1];
        }
    }

    for(i = 0; i < Q; i++){
        scanf("%d %d", &qS, &qE);

        if(arr[qS] == arr[qE])
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}