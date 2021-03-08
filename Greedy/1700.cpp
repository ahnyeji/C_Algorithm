/*  BOJ - 1700 : 멀티탭 스케줄링
    09.March.2021
 */

/*  [Greedy]
    # 이후로 쓰이지 않거나 가장 나중에 다시 쓰이는 플러그를 뽑는 것이 탐욕적
      1. 멀티탭에 빈 공간이 있으면 플러그 꽂기
      2. 이미 꽂혀있는 전기용품이면 다음 전기용품 확인
      3. 플러그를 뽑아야 함
        - 멀티탭에 꽂혀있는 전기용품 중 가장 나중에 다시 쓰이는 전기용품 찾기
        - 해당 플러그 뽑고 현재 꽂아야 하는 플러그 꽂기
 */

#include <iostream>

using namespace std;

int item[101];
int multi[101];

int main(){
    int N, K;
    cin >> N >> K;

    for(int i = 0; i < K; i++){
        cin >> item[i];
    }

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < K; i++){
        bool plugged = false;

        for(int j = 0; j < N; j++){ // plugged in?
            if(multi[j] == item[i]){
                plugged = true;
                break;
            }
        }

        if(!plugged && cnt < N){ // exist empty space 
            multi[cnt++] = item[i];
            plugged = true;
        }
        if(plugged) continue; // already plugged in
        
        int conIdx = 0; // index of multitap power socket
        int lastIdx = 0; // fastest index of last used item among items to be reused
        for(int j = 0; j < N; j++){ // item plugged in multitap power socket
            int idx = 0;
            for(int k = i + 1; k < K; k++){ // find current item's fastest reused index
                if(item[k] == multi[j]) break;
                idx++;
            }
            if(idx > lastIdx){
                lastIdx = idx;
                conIdx = j;
            }
        }
        
        multi[conIdx] = item[i];
        ans++;
        
    }
    cout << ans << "\n";
}