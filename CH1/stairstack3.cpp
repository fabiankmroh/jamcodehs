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

        if(lvl > 0 && (lvl % 4) == 0){
            s.pop();
            continue;
        }

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
        s.push(lvl+1);
        s.push(lvl+2);
    }

    printf("%d\n", cnt);

    return 0;
}