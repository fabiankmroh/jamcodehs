#include <stdio.h>
#include <stack>

using namespace std;

int main(void){
    stack<int> s;
    s.push(30);
    s.pop();
    printf("%d\n", s.top());

    return 0;
}