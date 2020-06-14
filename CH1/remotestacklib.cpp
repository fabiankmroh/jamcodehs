#include <stdio.h>
#include <stack>

using namespace std;

typedef struct node{
    int cnt;
    int temp;
} node;

int main(void){
    stack<node> s;
    int ct, dt;
    int min = 10000;

    scanf("%d %d", &ct, &dt);

    s.push((node){0, ct});
    node current;

    while(s.size() != 0){
        current = s.top();

        if(current.cnt > 5){
            s.pop();
            continue;
        }

        if(current.temp == dt){
            if(current.cnt < min){
                min = current.cnt;
            }
            s.pop();
            continue;
        }

        s.pop();

        s.push((node){current.cnt+1, current.temp+1});
        s.push((node){current.cnt+1, current.temp+5});
        s.push((node){current.cnt+1, current.temp+10});

        s.push((node){current.cnt+1, current.temp-1});
        s.push((node){current.cnt+1, current.temp-5});
        s.push((node){current.cnt+1, current.temp-10});
    }

    printf("%d\n", min);

    return 0;
}