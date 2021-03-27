/*  BOJ - 15732 : 도토리 숨기기
    03.March.2021
 */

/*  [Binary Search]
    # 상자 번호를 lo, hi, mid로 설정하여 범위를 좁혀나감
    # sum : mid를 마지막 상자라고 할 때 넣을 수 있는 도토리의 개수
      - sum < D : mid보다 큰 범위에서 다시 탐색 (mid 제외; lo = mid - 1)
      - sum >= D : mid보다 작은 범위에서 다시 탐색 (mid 제외; hi = mid + 1)
    => sum 구할 때 int 범위 넘어가는 경우 존재 -> long long 형 사용 (오답 원인)
 */

#include <iostream>

using namespace std;

int boxes[1000001][3];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, K, D;
    cin >> N >> K >> D;

    int lo = 1000000;
    int hi = 0;
    for(int i = 0; i < K; i++){
        cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];
        lo = boxes[i][0] < lo ? boxes[i][0] : lo;
        hi = boxes[i][1] > hi ? boxes[i][1] : hi;
    }
    int mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        long long sum = 0;
        for(int i = 0; i < K; i++){
            if(boxes[i][0] <= mid){
                sum++;
                if(boxes[i][1] >= mid){
                    sum += (mid - boxes[i][0]) / boxes[i][2];
                }
                else {
                    sum += (boxes[i][1] - boxes[i][0]) / boxes[i][2];
                }
            }
        }

        if(sum < D){
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << lo;
}