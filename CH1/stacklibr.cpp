#include <stdio.h>
#include <stack>

using namespace std;

int main(void){
    stack<int> s;
    int input;

    for(int i = 0; i < 5; i++){
        scanf("%d", &input);

        s.push(input);
    }

    for(int i = 0; i < 5; i++){
        printf("%d\n", s.top());
        s.pop();
    }
    
    return 0;
}