#include <stdio.h>

using namespace std;
int size, range;
char input[20100];
int i, j;
int ans = 0;

int main(void){
    scanf("%d %d", &size, &range);
    scanf("%s", input);
    //ans = 0;
    
    for(i = 0; i < size; i++){
        if(input[i] == 'P'){
            for(j = i-range; j <= i+range; j++){
                if(j < 0 || j >= size) continue; 
                if(input[j] == 'H'){
                    input[j] = 'N'; // Nothing
                    input[i] = 'N';
                    ans++;
                    break;
                }
            }
        }  
    }


    printf("%d\n", ans);
    return 0;
}