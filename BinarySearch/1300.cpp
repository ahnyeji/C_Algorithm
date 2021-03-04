/*  BOJ - 1300 : K번째 수
    04.March.2021
    (03.March.2021 Live Problem Solving)
 */

/*  [Binary Search]
    # A[i][j] 후보를 lo, hi, mid 설정
      - lo = 1 (1 * 1)
      - hi = N * N
    # cnt : mid 이하인 수의 개수 (정수 범위를 초과할 수 있음; 오답 이유)
      - cnt < k : 수 크기 늘려서 다시 탐색 (가운데 수 제외; lo = mid + 1)
      - cnt >= k : 수 크기 줄여서 다시 탐색 (가운데 수 제외; hi = mid - 1)
        => cnt == k일 때 mid 값이 배열의 수가 될 수 없는 경우도 있음 (오답 이유)
            예) N = 3, k = 8일 때 mid가 7인 경우 (답은 6)
 */

#include <iostream>

using namespace std;

int main(){
    long long N, k;
    cin >> N >> k;

    long long lo = 1;
    long long hi = N * N;
    int ans;
    while(lo <= hi){
        long long mid = (lo + hi) / 2;
        long long cnt = 0;
        for(long long i = 1; i <= N; i++){
            cnt += ((mid / i) < N ? (mid / i) : N);
        }
        if(cnt < k){
            lo = mid + 1;
        }
        else {
            ans = mid;
            hi = mid - 1;
        }
    }    
    cout << ans;
}