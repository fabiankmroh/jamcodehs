#include <iostream>
#include <cstdio>
#include <vector> // 벡터 사용하기 위해 필요
#include <algorithm> // sort 사용하기 위해 필요

#define DEBUG 0

int N;
int point[1000005][2]; //점 위치 데이터
int data[1000005][2]; //봉우리 양끝값 데이터

using namespace std;

int main(void){
    scanf("%d", &N);

    for(int i=0; i< N; i++){
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    
    int start; 
    int i = 0;

    while(point[i][1] > 0) 
        i++;

    start = i;

    int cnt=0;
    int cur=0; // data배열을 채우기 위한 커서

    while(cnt < N){
        int nowY = point[(start+cnt)%N][1];
        int nextY = point[(start+cnt+1)%N][1];
        
        // x축을 통과해 올라가는 지점
        if(nowY < 0 && nextY > 0){
            data[cur][0] = point[(start+cnt)%N][0];
            //printf("rise at %d\n",data[cur][0]);
        }

        // x축을 통과해 내려가는 지점
        if(nowY > 0 && nextY < 0){
            data[cur][1] = point[(start+cnt)%N][0];
            //printf("set at %d\n",data[cur][1]);
            cur++;
        }

        cnt++;
    }

    int datasize = cur;
    vector< pair<int, int> > v;

    for(int i=0;i<datasize;i++){
        if(data[i][0] < data[i][1]){
            pair<int, int> p;
            p = make_pair(data[i][0], data[i][1]);
            v.push_back(p);
        }
        else{
            pair<int, int> p;
            p = make_pair(data[i][1], data[i][0]);
            v.push_back(p);
        }
    }

    // 이제 각 봉우리의 왼쪽, 오른쪽 값을 저장하는 페어의 리스트가 만들어졌다. 정렬을 하면 된다.
    sort(v.begin(), v.end());

    // 아무것도 포함 안하는 봉우리 찾기
    int cnt1 = 0;

    for(int i = 0 ; i < v.size()-1; i++){
        if(v[i].second < v[i+1].first) 
            cnt1++;
    }
    cnt1++; // 좌측에서부터 볼 때 제일 마지막 봉우리는 무조건 아무것도 포함 안함
    // 어디에도 포함 안되는 봉우리 찾기
    // 로직: 첫번째 봉우리의 오른쪽 끝을 찾고, 그 우측 중 제일 먼저 나오는 봉우리를 찾고, 그 봉우리의 오른쪽 끝을 찾고, 그 우측 중 제일 먼저 나오는 봉우리를 찾고 하는 식으로
    
    int cnt2 = 0;
    int cursor2 = 0;
    
    cnt2++; //좌측에서부터 볼 때 제일 첫 봉우리는 무조건 어디에도 포함 안되므로 일단 1개 추가

    while(cursor2 < v.size()){
        int right = v[cursor2].second; // right는 현재 보고 있는 봉우리의 오른쪽 끝 좌표를 나타낸다.
        // 다음 봉우리(현재 봉우리의 오른쪽 끝보다 우측에 왼쪽 끝이 있는 봉우리 중에서 제일 먼저 나오는 것)
        while(v[cursor2].first < right){
            cursor2++;
            if(cursor2 > v.size()) break;
        }
        cnt2++;
    }
    cnt2--; //위의 while문 로직대로 한다면 무조건 하나가 더 늘게 되어 있다.
    
    if(DEBUG){
        for(int i=0;i<v.size();i++){
            printf("%d %d\n", v[i].first, v[i].second);
        }
        for(int i=0;i<datasize;i++){
            printf("%d %d\n", data[i][0], data[i][1]);
        }
    }
    printf("%d %d", cnt2, cnt1);
    return 0;
}