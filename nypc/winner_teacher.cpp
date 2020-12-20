#include <stdio.h>

#include <vector>

using namespace std;

int N, K;
int photo[10005];
int user_cnt[1005];
int photo_cnt_per_user[1005]; // 유저별 사진 찍힌 횟수 저장

vector<int> winner_list;

int main(){
    scanf("%d", &N);
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        scanf("%d", &photo[i]);
        photo_cnt_per_user[photo[i]]++;
    }
    for(int i = 1; i <= N; i++){ // i번 유저가 우승가능성 있는지 확인
        if(photo[0] == i){ // 첫번째 사진의 유저는 무조건 우승 가능성 있음
            winner_list.push_back(i);
            continue;
        }
        if(photo_cnt_per_user[i] == 0) continue; // 사진에 한번도 안찍힌 유저는 무조건 우승 불가.
        vector <int> v; // i번 유저의 사진 번호를 저장
        for(int j = 0; j < K; j++) if(photo[j] == i) v.push_back(j);
        for(int j = 0; j < v.size()-1; j++){
            int start = v[j];
            int end = v[j+1];
            int flag = 0;
            for(int k = 1; k <= N; k++){ // user_cnt 초기화
                user_cnt[k]=0;
            }
            for(int k = start+1; k < end; k++){
                user_cnt[photo[k]]++;
                if(user_cnt[photo[k]] > 1) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                winner_list.push_back(i);
                break;
            }
        }
    }
    printf("%d\n", winner_list.size());
    for(int i = 0; i < winner_list.size(); i++) 
        printf("%d ",winner_list[i]);
    return 0;
}
