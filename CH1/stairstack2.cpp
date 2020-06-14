#include <stdio.h>
#include <stack>

using namespace std;

int cnt, n;

int main(void){
    stack<int> s;

    scanf("%d", &n);

    s.push(0);
    int lvl;

    while(s.size() != 0){
        lvl = s.top();

        if(lvl == n){
            cnt++;
            s.pop();
            continue;
        }
        else if(lvl > n){
            s.pop();
            continue;
        }

        s.pop();
        s.push(lvl+3);
        s.push(lvl+5);
    }

    printf("%d\n", cnt);

    return 0;
}