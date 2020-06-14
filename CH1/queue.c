#include <stdio.h>

int front, rear;
int queue[10];

void put(int n){
    if(rear < 10){
        queue[rear] = n;
        rear++;
    }
    else{
        printf("Overflow\n");
    }

    return;
}

void get(void){
    if(front != rear){
        front++;
        return;
    }
    else{
        printf("Empty Queue\n");
    }
}

void size(void){
    printf("%d\n", rear-front);

    return;
}

void empty(void){
    if(front != rear)
        printf("0\n");
    else
        printf("1\n");

    return;
}

void print(void){
    for(int i = front; i < rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");

    return;
}

int main(void){
    put(1);
    put(3);
    put(5);
    size();
    empty();
}