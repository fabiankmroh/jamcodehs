#include <stdio.h>

int score[2500][2500];
int cardN;
int maxScore = 0;
int i, j;

int left[2500];
int right[2500];

int main(void){
    scanf("%d", &cardN);

    for(i = 0; i < cardN; i++){
        scanf("%d", &left[i]);
    }

    for(i = 0; i < cardN; i++){
        scanf("%d", &right[i]);
    }

    for(i = 0; i <= cardN; i++){
        for(j = 0; j <= cardN; j++){
            score[i][j] = -1;
        }
    }

    /* -1 칸은 한번도 변한 적 없기 때문에 도달 불가 */

    score[0][0] = 0;

    for(i = 0; i <= cardN; i++){
        for(j = 0; j <= cardN; j++){
            int cs = score[i][j];
            if(cs < 0)
                continue;
        
            // Rule #1
            if(score[i+1][j+1] < cs) // Both cards
                score[i+1][j+1] = cs;
            if(score[i+1][j] < cs) // Left cards
                score[i+1][j] = cs;

            // Rule #2
            if(left[i] > right[j]){
                if(score[i][j+1] < cs + right[j])
                    score[i][j+1] = cs + right[j];
            }
        }
    }

    for(i = 0; i <= cardN; i++){
        int s = (score[i][cardN-1] > score[cardN-1][i]) ? score[i][cardN-1] : score[cardN-1][i];

        if(s > maxScore){
            maxScore = s;
        }
    }


    printf("%d\n", maxScore);

    return 0;
}