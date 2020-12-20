#include <stdio.h>

int T, i;

int ally[4];
int opponent[4];

int itemW, speedW;

int aM, oM;
int aT, oT;

int main(void){
    scanf("%d", &T);

    for(int cnt = 0; cnt < T; cnt++){
        itemW = 0;
        speedW = 0;

        aT = 0;
        oT = 0;

        aM = 0;
        oM = 0;
        
        for(i = 0; i < 4; i++){
            scanf("%d", &ally[i]);

            aT += ally[i];
            
            if(ally[i] > aM)
                aM = ally[i];
        }

        for(i = 0; i < 4; i++){
            scanf("%d", &opponent[i]);

            oT += opponent[i];

            if(opponent[i] > oM)
                oM = opponent[i];
        }

        if(aT > oT){
            speedW = 1;
        }
        if(aM > oM){
            itemW = 1;
        }

        if(speedW == 1 && itemW == 0){
            printf("S\n");
        }

        if(itemW == 1 && speedW == 0){
            printf("I\n");
        }

        if(itemW == speedW){
            printf("R\n");
        }
    }

    return 0;
}
