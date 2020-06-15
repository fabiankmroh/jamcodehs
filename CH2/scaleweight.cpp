#include <stdio.h>
#include <queue>
#include <memory.h>

using namespace std;

int choo[7] = {1,3,9,27,81,243,729};
int input;

typedef struct weight{
    int w[7];
    int l;
    int r;
    int pN;
} w;

void print(w scale){
    int i;
    
    printf("%d ", input);

    // Left Side
    for(i = 0; i < 7; i++){
        if(scale.w[i] == 1){
            printf("%d ", choo[i]);
        }
    }

    printf("0 ");

    // Right Side
    for(i = 0; i < 7; i++){
        if(scale.w[i] == 2){
            printf("%d ", choo[i]);
        }
    }
    
    printf("\n");

    return;
}

int main(void){
    queue<w> s;
    scanf("%d", &input);
    int d[7] = {0,0,0,0,0,0,0};
    w first;
    memcpy(first.w,d,sizeof(d));
    first.l=input;
    first.r=0;
    first.pN=0;
    s.push(first); 
    
    while(!s.empty()){
        int cL = s.front().l;
        int cR = s.front().r;
        int cN = s.front().pN;
        int n[7];
        memcpy(n, s.front().w, sizeof(n));
        if(cL == cR){
            print(s.front());
            break;
        }
        if(cN == 7){
            s.pop();
            continue;
        }
        s.pop();
        n[cN] = 0; // Blank;
        w next;
        memcpy(next.w,n,sizeof(n)); // Creating next struct
        next.l=cL;
        next.r=cR;
        next.pN=cN+1;
        s.push(next);

        n[cN] = 1; // Left
        memcpy(next.w,n,sizeof(n)); // Creating next struct

        next.l=cL+choo[cN]; 
        next.r=cR;
        next.pN=cN+1;
        s.push(next);

        n[cN] = 2; // Right
        
        memcpy(next.w,n,sizeof(n)); // Creating next struct

        next.l=cL; 
        next.r=cR+choo[cN];
        next.pN=cN+1;
        s.push(next);
        
    }

}