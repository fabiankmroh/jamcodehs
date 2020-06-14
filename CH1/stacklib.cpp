#include <stdio.h>
#include <stack>

using namespace std;

int main(void){
    stack<int> s;
    s.push(10);
    s.push(15);
    printf("%d\n", s.top());

    return 0;
}