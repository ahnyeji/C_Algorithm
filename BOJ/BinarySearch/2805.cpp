/*  BOJ - 2805 : 나무 자르기
    03.March.2021
 */

/*  [Binary Search]
    # 절단기 설정 높이를 lo, hi, mid로 설정하여 범위를 좁혀나감
    # sum : mid를 절단기 설정 높이로 할 때 가져갈 수 있는 나무 높이 합
      - sum == M : 정답 찾았으므로 탐색 종료
      - sum > M : mid보다 큰 범위에서 다시 탐색 (mid 제외; hi = mid + 1)
      - sum < M : mid보다 작은 범위에서 다시 탐색 (mid 제외; lo = mid - 1)
    => sum 구할 때 int 범위 넘어가는 경우 존재 -> long long 형 사용 (오답 원인)
 */

#include <iostream>
using namespace std;

long long height[1000000];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int hi = 0;
    for(int i = 0; i < N; i++){
        cin >> height[i];
        hi = hi < height[i] ? height[i] : hi;
    }

    int lo = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        long long sum = 0;
        for(int i = 0; i < N; i++){
            if(height[i] - mid > 0) sum += (height[i] - mid);
        }
        if(sum == M){
            hi = mid;
            break;
        }
        if(sum > M){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    cout << hi;
}