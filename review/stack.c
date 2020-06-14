#include <stdio.h>

int top = 0;
int stack[15];
int tmp;

void push(int input){
    if(top < 15){
        stack[top] = input;
        top++;
    }
    else{
        printf("Overflow\n");
    }

    return;
}

void pop(void){
    if(top > 0)
        top--;
    else
        printf("Nothing to pop\n");
    
    return;
}

void print(void){
    if(top == 0){
        printf("Stack is empty\n");
        return;
    }
    for(int i = 0; i < top; i++){
        printf("%d ", stack[i]);
    }

    printf("\n");
    return;
}

void size(void){
    printf("%d\n", top);
    return;
}

void empty(void){
    if(top == 0)
        printf("1\n");
    else
        printf("0\n");
    return;
}

void reverse(void){
    for(int i = top-1; i >= 0; i--){
        printf("%d ", stack[i]);
    }
    printf("\n");

    return;
}

int main(void){
    int i;

    for(i = 0; i < 5; i++){
        scanf("%d", &tmp);

        push(tmp);
    }

    reverse();
    return 0;
}