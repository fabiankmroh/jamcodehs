#include <stdio.h>

int stack[10];
int top;
int tmp;

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

void reverse(void){
    for(int i = top-1; i >= 0; i--)
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
    for(int i = 0; i < 5; i++){
        scanf("%d", &tmp);

        push(tmp);
    }
    
    reverse();

    return 0;
}