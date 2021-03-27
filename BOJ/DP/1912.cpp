/*  BOJ - 1912 : 연속합
    16.February.2021
 */

/*  [DP]
    # 기저사례
      - maxsum[0] : INPUT (수열 시작점)
    # 점화식
      - maxsum[i] = max(INPUT, maxsum[i - 1] + INPUT);
        => INPUT : INPUT이 이전까지의 maxsum을 더한 것 보다 크다면 새로운 연속합 시작
        => maxsum[i - 1] + INPUT : 이전까지의 maxsum을 더한 값이 더 크다면 기존 연속합 갱신
    # 최대값
      - 가장 큰 연속합 (계산할 때마다 비교)
 */

#include <iostream>
using namespace std;

int maxsum[100001];

int main(){
    int n;
    cin >> n;

    cin >> maxsum[0];
    int ans = maxsum[0];
    for(int i = 1; i < n; i++){
        cin >> maxsum[i];
        maxsum[i] = maxsum[i] < maxsum[i - 1] + maxsum[i] ? maxsum[i - 1] + maxsum[i] : maxsum[i];
        ans = ans < maxsum[i] ? maxsum[i] : ans;
    }

    cout << ans;
}