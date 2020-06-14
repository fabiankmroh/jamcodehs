#include <stdio.h>
#include <queue>

using namespace std;

int main(void){
    queue<int> q;

    q.push(10);
    q.push(18);
    q.pop();
    printf("%d\n", q.front());

    return 0;
}