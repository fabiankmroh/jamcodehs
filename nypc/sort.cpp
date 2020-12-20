#include <stdio.h>

int curr;
char order[100010];

int main(void){
    scanf("%s", order);
    
    int i = 0;
    while(order[i] != NULL){
        if(order[i] == 'S')
            curr++;
        if(order[i] == 'T'){
            curr++;
            while(curr % 4 != 0)
                curr++;
        }

        i++;
    }
    
    printf("%d\n", curr);
}