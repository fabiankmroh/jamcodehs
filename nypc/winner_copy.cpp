#include <stdio.h>
#include <vector>

using namespace std;

int N, K;
int i, j, k;

int photo[10005];
int photo_cnt_per_user[1005];

int user_cnt[1005];
vector<int> position;

vector<int> winner;

int main(void){
    scanf("%d %d", &N, &K);

    for(i = 0; i < K; i++){
        scanf("%d", &photo[i]);
        photo_cnt_per_user[photo[i]]++;
    }

    for(i = 1; i <= N; i++){
        if(photo[0] == i){
            winner.push_back(i);
            continue;
        }
        if(photo_cnt_per_user[i] == 0)
            continue;
        
        for(j = 0; j < K; j++){
            if(photo[j] == i)
                position.push_back(j);
        }

        for(j = 0; j < position.size()-1; j++){
            int start = position[j];
            int end = position[j+1];
            int win = 0;

            for(k = 1; k <= N; k++){
                user_cnt[k] = 0; // Reset user_cnt
            }

            for(k = start+1; k < end; k++){
                user_cnt[photo[k]]++;
                
                if(user_cnt[photo[k]] > 1){
                    win = 1;
                    break;
                }
            }

            if(win == 0){
                winner.push_back(i);
                break;
            }
        }
    }

    // Print how many racers can be winners
    printf("%d\n", winner.size());

    // Print Potential-Winner Racer #
    for(i = 0; i < winner.size(); i++){
        printf("%d ", winner[i]);
    }
    printf("\n");

    return 0;
}