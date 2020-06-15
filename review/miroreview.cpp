#include <stdio.h>
#include <queue>

using namespace std;

char map[100][100];
int height, width;
int sx, sy;

typedef struct location{
    int x;
    int y;
    int dist;
} loc;

int main(void){
    queue<loc> q;
    scanf("%d %d", &height, &width);

    int i, j;

    for(i = 0; i < height; i++){
        scanf("%s", map[i]);
        for(j = 0; j < width; j++){
            if(map[i][j] == 'S'){
                sx = i;
                sy = j;
            }
        }
    }

    q.push((loc){sx, sy, 0});
    loc c; /* for current */

    while(!q.empty()){
        c = q.front();

        if(map[c.x][c.y] == 'G'){
            printf("%d\n", c.dist);

            return 0;
        }

        q.pop();

        if(map[c.x+1][c.y] != '#' && c.x+1 < width)
            q.push((loc){c.x+1, c.y, c.dist+1});
        if(map[c.x-1][c.y] != '#' && c.x-1 >= 0)
            q.push((loc){c.x-1, c.y, c.dist+1});

        if(map[c.x][c.y+1] != '#' && c.y+1 < height)
            q.push((loc){c.x, c.y+1, c.dist+1});
        if(map[c.x][c.y-1] != '#' && c.y-1 >= height)
            q.push((loc){c.x, c.y-1, c.dist+1});
    }

    return 0;
}