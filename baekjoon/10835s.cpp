#include <stdio.h>

int score[2000][2000];
int cardN;
int maxScore = 0;
int i, j;

int left[2000];
int right[2000];

int main(void){
    scanf("%d", &cardN);

    for(i = 0; i < cardN; i++){
        scanf("%d", &left[i]);
    }

    for(i = 0; i < cardN; i++){
        scanf("%d", &right[i]);
    }

    for(i = 0; i < cardN; i++){
        for(j = 0; j < cardN; j++){
            int cs = score[i][j];

            // Rule #1
            if(score[i+1][j+1] < cs) // Both cards
                score[i+1][j+1] = cs;
            if(score[i+1][j] < cs) // Left cards
                score[i+1][j] = cs;
            
            // Rule #2
            if(left[i] > right[j]){
                if(score[i][j+1])
                    score[i][j+1] = cs + right[j];
            }
        }
    }

    for(i = 0; i < cardN; i++){
        int s = (score[i][cardN-1] > score[cardN-1][i]) ? score[i][cardN-1] : score[cardN-1][i];

        if(s > maxScore){
            maxScore = s;
        }
    }


    printf("%d\n", maxScore);
}