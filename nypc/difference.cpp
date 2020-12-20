#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

#define DEBUG   0

using namespace std;

int pS;
int member;
int lounge;
int i;
int score[500100];

vector<pair<int, int> > diff;

int main(void){
    scanf("%d", &lounge);

    scanf("%d %d", &pS, &member);

    for(i = 0; i < lounge; i++){
        scanf("%d", &score[i]);

       diff.push_back(make_pair(abs(pS-score[i]),i));
    }

    sort(diff.begin(), diff.end());

    if(DEBUG){
        printf("\n\nVector:\n");
        for(i = 0; i < member; i++){
            printf("%d  ", score[diff[i].second]);
            printf("%d %d\n", diff[i].first, diff[i].second+1);
        }
        printf("\n\n");
    }

    for(i = 0; i < member; i++){
        if(i == member-1 && diff[i].first == diff[i+1].first){
            if(score[diff[i].second] > score[diff[i+1].second]){
                printf("%d ", diff[i+1].second+1);
                break;
            }
            else{
                printf("%d ", diff[i].second+1);
                break;
            }
            printf("failed\n");
        }
        else{
            printf("%d ", diff[i].second+1);
        }
    }
    printf("\n");

    return 0;
}