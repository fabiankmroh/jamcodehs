#include <stdio.h>

using namespace std;

int input;
int qloc[9];

int checkS(int x, int y){
    int i, j;

    for(i = x; i >= 0; i--){
        for(j = y; j >= 0; j--){
            if(qloc[i] == j){
                return 0;
            } 
        }
    }

    for(i = x; i < input; i++){
        for(j = y; j >= 0; j--){
            if(qloc[i] == j){
                return 0;
            }
        }
    }

    /* Up */
    for(j = y; j >= 0; j--){
        if(qloc[x] == j){
            return 0;
        }
    }

    return 1;
}
