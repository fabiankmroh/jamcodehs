#include <stdio.h>
#include <vector>
#include <algorithm>

#define DEBUG 0

using namespace std;

int n;
vector <pair<int, int> > h;
vector <pair<int, int> > v;
int data[100010][2];
int horiz[1000010]; 
int verti[1000010]; 

int main(void){
   scanf("%d", &n);

   for(int i = 0; i < n; i++){
       scanf("%d %d", &data[i][0], &data[i][1]);
   }

   data[n][0] = data[0][0];
   data[n][1] = data[0][1];
   
   for(int i = 0; i < n; i++){
       if(data[i][0] == data[i+1][0]){
           if(data[i][1] > data[i+1][1]){
               v.push_back(make_pair(data[i+1][1], data[i][1]));
           }
           else{
               v.push_back(make_pair(data[i][1], data[i+1][1]));
           }
       }
       
       if(data[i][1] == data[i+1][1]){
           if(data[i][0] > data[i+1][0]){
               h.push_back(make_pair(data[i+1][0], data[i][0]));
           }
           else{
               h.push_back(make_pair(data[i][0], data[i+1][0]));
           }
       }
   }

   for(int i = 0; i < h.size(); i++){
       int left = h[i].first + 500000;
       int right = h[i].second + 500000;
       
       horiz[left]++;
       horiz[right]--;
   }
   
   for(int i = 0; i < v.size(); i++){
       int down = v[i].first + 500000;
       int up = v[i].second + 500000;
       verti[down]++;
       verti[up]--;
   }
   
   int cnt = 0;
   int max = 0;
   for(int i = 0; i < 1000005; i++){
       cnt += horiz[i];
       max = max < cnt ? cnt : max;
   }

   cnt = 0;
   for(int i = 0; i < 1000005; i++){
       cnt += verti[i];
       max = max < cnt ? cnt : max;
   }
   
   printf("%d\n", max);
   
   return 0;
}