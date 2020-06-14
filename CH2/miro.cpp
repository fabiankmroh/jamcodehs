#include <stdio.h>
#include <queue>

using namespace std;

char map[100][100];
int maph, mapw;
int startx, starty;

typedef struct location{
    int x;
    int y;
    int dist;
} loc;

int main(void){
    queue<loc> q;
    scanf("%d %d", &maph, &mapw);

    int i, j;

    for(i = 0; i < maph; i++){
        scanf("%s", map[i]);
        for(j = 0; j < mapw; j++){
            if(map[i][j] == 'S'){
                startx = i;
                starty = j;
            }
        }
    }

    q.push((loc){startx, starty, 0});
    loc c; /* for current */

    while(!q.empty()){
        c = q.front();

        if(map[c.x][c.y] == 'G'){
            printf("%d\n", c.dist);

            return 0;
        }

        q.pop();
        if(map[c.x+1][c.y] != '#' && c.x+1 < mapw)
            q.push((loc){c.x+1, c.y, c.dist+1});
        if(map[c.x-1][c.y] != '#' && c.x-1 >= 0)
            q.push((loc){c.x-1, c.y, c.dist+1});
        if(map[c.x][c.y+1] != '#' && c.y+1 < maph)
            q.push((loc){c.x, c.y+1, c.dist+1});
        if(map[c.x][c.y-1] != '#' && c.y-1 >= maph)
            q.push((loc){c.x, c.y-1, c.dist+1});
    }

    return 0;
}