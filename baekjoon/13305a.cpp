#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector< pair<int, int> > v; // City #, Oil Price
int dist[100010];
int checked[100010];
vector<int> stop; // 저렴한 주유소 멈춰야해는 곳
int N, i, tmp;

int main(void){
    scanf("%d", &N);


    // Distance between cities
    for(i = 1; i < N; i++){
        scanf("%d", &dist[i]);
    }

    for(i = 0; i < N; i++){
        scanf("%d", &tmp);

        v.push_back(make_pair(tmp, i+1));
    }

    sort(v.begin(), v.end()); // 가장 저렴한 주유소가 앞에 와있다.
    
    int lowCity = v[0].second; // 가장 저렴한 주유소의 도시 # init

    while(minA != 1){
        int min = 1000000001;
        int minA;
        for(int i = 0; i < lowCity; i++){
            if(v[i].first < min){
                min = v[i].first;
                minA = v[i].second;
            }
        }
        lowCity = minA;

        stop.push_back(minA);
    }

    for(i = stop.size()-1; i = 0; i--){
        if()
    }
}