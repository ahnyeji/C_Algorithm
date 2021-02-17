/*  BOJ - 2579 : 계단 오르기
    17.February.2021
 */

/*  [DP]
    # 변수
      - stairs[] : 각 계단의 값 저장 공간
      - cache[][] : dp 계산 값 저장 공간 -> 마지막 계단인 n-1부터 시작 // (이번 : i, 이전 : i+1) 순
        => cache[i][0] : 연속해서 계단을 밟았을 경우 (o,o)
        => cache[i][1] : 이전 계단을 밟지 않고 이번 계단을 밟을 경우 (o,x)
        => cache[i][2] : 이번 계단을 밟을 경우 (x,o) // 계단은 한 번만 건너뛸 수 있음 (이번 계단을 밟지 않으려면 이전 계단 무조건 밟아야 함)
    # 기저사례 : 무조건 마지막 계단은 밟아야 함 (이 부분 확인 안해서 오답)
      - cache[n - 1][0] = stairs[n - 1] : 현재 계단을 밟았으므로 stairs[n - 1]
      - cache[n - 1][1] = stairs[n - 1] : 현재 계단을 밟았으므로 stairs[n - 1]
      - cache[n - 1][2] = -3000000 : 현재 계단을 밟지 않음 -> 불가능한 경우이므로 어떤 계단을 선택하는 경우에도 최대가 되지 않도록 초기값 설정
        => 이부분 확인 안해서 오답
    # 점화식
      - cache[i][0] = stairs[i] + cache[i + 1][1];
        => 이전 계단은 밟고 그 전 계단은 밟지 않아야 연속 최대 2회 조건 만족 -> (o : i, o : i + 1, x : i + 2)
      - cache[i][1] = stairs[i] + cache[i + 1][2];
        => 이전 계단 밟지 않아야 함 -> (o : i, x : i + 1, o : i + 2)
      - cache[i][2] = max(cache[i + 1][0], cache[i + 1][1]);
        => cache[i + 1][0] : (x : i, o : i + 1, o : i + 2)
        => cache[i + 1][1] : (x : i, o : i + 1, x ; i + 2)
        => 둘 중 최대값 선택

*/

#include <iostream>
#include <algorithm>
using namespace std;

int stairs[300];
int cache[300][3];

int main(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> stairs[i];
    }

    // base case
    cache[n - 1][0] = stairs[n - 1];
    cache[n - 1][1] = stairs[n - 1];
    cache[n - 1][2] = -3000000;

    // dp
    for(int i = n - 2; i >= 0; i--){
        cache[i][0] = stairs[i] + cache[i + 1][1]; // select - continuous
        cache[i][1] = stairs[i] + cache[i + 1][2]; // select - discontinuous
        cache[i][2] = max(cache[i + 1][0], cache[i + 1][1]); // not select
    }
    cout << max(cache[0][0], max(cache[0][1], cache[0][2]));
}