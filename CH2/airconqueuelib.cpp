#include <stdio.h>
#include <queue>

using namespace std;

typedef struct n{
    int cnt;
    int temp;
}node;

int main(void){
    queue<node> q;
    int min = 1000;
    int a, b;

    scanf("%d %d", &a, &b);

    q.push((node){0, a});

    node c;

    while(q.size() != 0){
        c = q.front();

        if(c.cnt > 5){
            q.pop();
            continue;
        }

        if(c.temp == b){
            if(c.cnt < min)
                min = c.cnt;
            
            q.pop();
            continue;
        }

        q.pop();
        q.push((node){c.cnt+1, c.temp+1});
        q.push((node){c.cnt+1, c.temp+5});
        q.push((node){c.cnt+1, c.temp+10});

        q.push((node){c.cnt+1, c.temp-1});
        q.push((node){c.cnt+1, c.temp-5});
        q.push((node){c.cnt+1, c.temp-10});
    }

    printf("%d\n", min);
}