#include <stdio.h>
#include <stack>

using namespace std;

int cnt = 0;

typedef struct node{
    int current;
    int color;
} n;

int main(void){
    stack<n> s;
    int itotal, icolor;

    scanf("%d %d", &itotal, &icolor);
    
    s.push((n){0,0});
    n c;

    while(s.size() != 0){
        c = s.top();
        if(c.current == itotal){
            if(c.color == icolor){
                cnt++;
                s.pop();
                continue;
            }
            else{
                s.pop();
                continue;
            }
        }

        s.pop();
        s.push((n){c.current+1, c.color+1});
        s.push((n){c.current+1, c.color});
    }

    printf("%d\n", cnt);

    return 0;
}