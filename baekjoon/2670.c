#include <stdio.h>

int product[10000] = { 1, };

int main(void){
    int n, i, j;
    int max = 0; 
    int arr[10000];

    scanf("%d", &n);

    for(j = 0; j < n; j++){
        scanf("%d", &arr[j]);
    }

    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    arr[0] = product[0];

    for(i = 1; i < n; i++){
        if(product[i-1] < 1){
            product[i] = arr[i];
        }
        else{
            product[i] = arr[i] * product[i-1];
        }
    }

    for(i = 0; i < n; i++){
        if(max < product[i])
            max = product[i];
    }

    printf("%d\n", max); */
}