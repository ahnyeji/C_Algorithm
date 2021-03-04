/*  BOJ - 2512 : 예산
    03.March.2021
    (03.March.2021 Live Problem Solving)
 */

/*  [Binary Search]
    # 상한액을 lo, hi, mid로 설정하여 범위를 좁혀나감
    # sum : mid를 상한액이라고 할 때 배정할 수 있는 예산 총액
      - sum > budget : 상한액을 줄여서 다시 탐색 (가운데 수 제외; hi = mid - 1)
      - sum <= budget : 상한액을 늘려서 다시 탐색 (가운데 수 제외; lo = mid + 1)
 */

#include <iostream>

using namespace std;

int ask[100000]; // asked budget

int main(){
    int N;
    cin >> N;

    int maxi = 0;
    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> ask[i];
        maxi = maxi < ask[i] ? ask[i] : maxi;
        sum += ask[i];
    }

    int budget;
    cin >> budget;

    if(sum <= budget){ // can allocate all asked budget
        cout << maxi;
        return 0;
    }

    int lo = 1;
    int hi = budget;
    int mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        
        sum = 0;
        for(int i = 0; i < N; i++){
            if(ask[i] > mid){
                sum += mid;
            }
            else {
                sum += ask[i];
            }
        }
        if(sum > budget){
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << hi;
}