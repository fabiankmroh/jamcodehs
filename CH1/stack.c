#include <stdio.h>

int stack[10];
int top;

void push(int input){
    if(top <= 10){
        stack[top] = input;
        top++;
    }
    else{
        printf("Overflow\n");
    }

    return;
}

void pop(void){
    if(top > 0){
        top--;
    }
    else{
        printf("Nothing to pop\n");
    }

    return;
}

void print(void){
    for(int i = 0; i < top; i++)
        printf("%d\n", stack[i]);

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

int main(void){
    empty();
    push(1);
    push(3);
    push(5);
    push(18);
    size();
    pop();
    size();
    empty();
    
    return 0;
}