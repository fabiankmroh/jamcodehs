#include <stdio.h>
#include <queue>

using namespace std;

int main(void){
    queue<int> s;
    int cnt = 0;
    s.push(0);

    int current;
    while(s.size() != 0){
        current = s.front();

        if(current == 4){
            cnt++;
            s.pop();
            continue;
        }
        else if(current > 4){
            s.pop();
            continue;
        }

        s.pop();
        s.push(current+1);
        s.push(current+2);
    }

    printf("%d\n", cnt);
    return 0;
}