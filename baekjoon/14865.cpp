#include <stdio.h>
#include <vector>
#include <algorithm>

int N;
int point[1000005][2];
int data[1000005][2];

using namespace std;

int main(void){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    
    int start; 
    int i = 0;

    while(point[i][1] > 0) 
        i++;

    start = i;

    int cnt = 0;
    int curr = 0;

    while(cnt < N){
        int nowY = point[ (start + cnt) % N ][1];
        int nextY = point[ (start + cnt + 1) % N ][1];
        
        if(nowY < 0 && nextY > 0){
            data[curr][0] = point[ (start + cnt) % N ][0];
        }

        if(nowY > 0 && nextY < 0){
            data[curr][1] = point[ (start + cnt) % N ][0];
            curr++;
        }

        cnt++;
    }

    int datasize = curr;
    vector< pair<int, int> > v;

    for(int i = 0; i < datasize; i++){
        pair<int, int> p;

        if(data[i][0] < data[i][1])
            p = make_pair(data[i][0], data[i][1]);
        else
            p = make_pair(data[i][1], data[i][0]);

        v.push_back(p);
    }

    sort(v.begin(), v.end());

    int cnt1 = 0;

    for(int i = 0; i < v.size()-1; i++){
        if(v[i].second < v[i+1].first)
            cnt1++;
    }
    cnt1++;

    int cnt2 = 0;
    int cursor2 = 0;

    cnt2++;

    while(cursor2 < v.size()){
        int right = v[cursor2].second;

        while(v[cursor2].first < right){
            cursor2++;
            if(cursor2 > v.size())
                break;
        }
        cnt2++;
    }
    cnt2--;

    printf("%d %d\n", cnt2, cnt1);
    return 0;
}