#include <stdio.h>

int qLoc[10];
int size;
int cnt = 0;

void queen(int n, int qPos){
    int i, j;
    int flag; // Used to determine if queen can be placed at the location

    if(n == size-1){ // Exit Case 
        cnt++; // Queen placed last row -> New Combination 
        return; 
    }

    qLoc[n] = qPos; // Queen's Position: qLoc[row] = column 

    for(i = 0; i < size; i++){ // Check if queen can be placed at specific column 
        flag = 0;

        for(j = 0; j <= n; j++){
            if(qLoc[j] == i)
                flag = 1; // Perpendicular Vertical Check 

            else if(j + qLoc[j] == n+1+i)
                flag = 1; // Right Upper Check (Sum of row and column values are equal) 

            else if(j - qLoc[j] == n+1-i)
                flag = 1; // Left Upper Check (Difference of row and column values are equal) 
        }

        if(flag == 0)
            queen(n+1, i);            
    }

    return;
}

int main(void){
    int k;

    scanf("%d", &size);

    for(k = 0; k < size; k++){
        queen(0, k);
    }

    printf("%d\n", cnt);
    return 0;
}