/*  BOJ - 1654 : 랜선 자르기
    06.March.2021
    (06.March.2021 Live Problem Solving)
 */

/*  [Binary Search]
    # 랜선 기준 길이를 lo, hi, mid 설정
    # 랜선 기준 길이가 mid일 때 만들 수 있는 랜선 개수 확인
      - >= N : 더 긴 랜선 길이 탐색 (최장 길이 찾아야 하므로; lo = mid + 1)
      - < N : 더 짧은 랜선 길이 탐색 (N개를 만들 수 없으므로 더 짧은 길이에서 찾아야 함; hi = mid - 1)
    # 랜선 기준 길이가 2^31 - 1이 될 수 있을 때, lo에서 overflow 발생 (2^31 되어서) -> long long 형 사용(오답 원인)
 */

#include <iostream>

using namespace std;

int main(){
  int K, N;
  cin >> K >> N;
  long long lines[10000];
  long long hi = 0;
  for(int i = 0; i < K; i++){
    cin >> lines[i];
    hi = hi < lines[i] ? lines[i] : hi;
  }

  long long lo = 1;
  long long mid;
  while(lo <= hi){
    mid = (lo + hi) / 2;
    long long cnt = 0;
    for(int i = 0; i < K; i++){
      cnt += lines[i] / mid;
    }
    if(cnt >= N){
      lo = mid + 1;
    }
    else {
      hi = mid - 1;
    }
  }
  cout << hi << "\n";
}
