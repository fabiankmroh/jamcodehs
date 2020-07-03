#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define DEBUG 0
using namespace std;

int n;
vector <pair<int, int> > h; // 수평 변들 저장
vector <pair<int, int> > v; // 수직 변들 저장
int data[100010][2]; // 원본 데이터 저장
int harr[1000010]; // 수평 변들이 겹치는 데이터를 표시
int varr[1000010]; // 수직 변들이 겹치는 데이터를 표시


int main(void){
   scanf("%d", &n);
   for(int i = 0; i < n; i++){
       cin >> data[i][0] >> data[i][1];
   }
   // 한바퀴를 돌아야 하므로 편의를 위해 첫 점의 좌표를 맨 뒤에 한번 더 써준다.
   data[n][0] = data[0][0];
   data[n][1] = data[0][1];
   
   // 원본 데이터 배열을 보면서 v와 h벡터를 채운다.
   for(int i = 0; i < n; i++){
       // i번째와 i+1번째 점이 수직 선분인 경우
       if(data[i][0] == data[i+1][0]){
           if(data[i][1] > data[i+1][1]) v.push_back(make_pair(data[i+1][1], data[i][1]));
           else v.push_back(make_pair(data[i][1], data[i+1][1]));
       }
       
       // i번째와 i+1번째 점이 수평 선분인 경우
       if(data[i][1] == data[i+1][1]){
           if(data[i][0] > data[i+1][0]) h.push_back(make_pair(data[i+1][0], data[i][0]));
           else h.push_back(make_pair(data[i][0], data[i+1][0]));
       }
   }
   
   // 벡터에 있는 수평 변들을 하나씩 보면서, 변의 시작 좌표에 해당하는 인덱스는 1 키우고, 변이 끝나는 좌표에 해당하는 인덱스는 1 뺀다.
   // 좌표는 -500000 에서 시작하므로, 변의 좌표에 500000을 더한 것을 배열의 인덱스로 한다.
   for(int i = 0; i < h.size(); i++){
       int left = h[i].first + 500000;
       int right = h[i].second + 500000;
       harr[left]++;
       harr[right]--;
   }
   
   // 수직도 마찬가지
   for(int i = 0; i < v.size(); i++){
       int down = v[i].first + 500000;
       int up = v[i].second + 500000;
       varr[down]++;
       varr[up]--;
   }
   
   // 안성된 h와 v 배열을 보면서 제일 많이 겹쳤을 때가 몇장인지 센다.
   int cnt = 0;
   int max = 0;
   for(int i = 0; i < 1000005; i++){
       cnt += harr[i];
       if(DEBUG){
           if(harr[i] != 0) cout << "harr index " << i << ": " << harr[i] << endl;
       }
       max = max < cnt ? cnt : max;
   }
   cnt = 0;
   for(int i = 0; i < 1000005; i++){
       cnt += varr[i];
       if(DEBUG){
           if(varr[i] != 0) cout << "varr index " << i << ": " << varr[i] << endl;
       }
       max = max < cnt ? cnt : max;
   }
   
   cout << max;
   
   return 0;
}