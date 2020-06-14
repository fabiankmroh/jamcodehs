#include <stdio.h>
#include <queue>

using namespace std;

int main(void){
    queue<int> s;
    int cnt = 0;
    int input;
    s.push(0);

    scanf("%d", &input);

    int current;
    while(s.size() != 0){
        current = s.front();

        if(current == input){
            cnt++;
            s.pop();
            continue;
        }
        else if(current > input){
            s.pop();
            continue;
        }

        s.pop();
        s.push(current+3);
        s.push(current+5);
    }

    printf("%d\n", cnt);
    return 0;
}