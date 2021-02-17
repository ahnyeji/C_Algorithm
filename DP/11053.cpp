/*  BOJ - 11053 : 가장 긴 증가하는 부분 수열
    16.February.2021
 */

/*  [DP]
    # 부분수열 : 수열의 일부 항을 원래 순서대로 나열하여 얻을 수 있는 수열 -> 순서만 지키면 연속되지 않아도 됨
    # 변수
      - seq[] : 수열 값 저장 공간
      - count[] : 해당 인덱스를 포함하는 부분 수열의 길이 저장 공간
    # 점화식
      - 현재 인덱스 이전 인덱스들 모두 확인(확인 과정에서 최대값으로 갱신)
      - 현재 인덱스 > 이전 인덱스 : 증가 부분 수열 o
        => 이전 인덱스 부분 수열 길이 + 1
      - 현재 인덱스 <= 이전 인덱스 : 증가 부분 수열 x
        => 1

*/

#include <iostream>
using namespace std;

int seq[1000];
int count[1000];

int main(){
    int N;
    cin >> N;
    int maxlen = 1;
    for(int i = 0; i < N; i++){
        cin >> seq[i];
        for(int j = i - 1; j >= 0; j--){ // check previous indexes
            if(seq[j] < seq[i] && count[j] > count[i]) count[i] = count[j]; // increasing sequence
        }
        count[i]++; // if all previous indexes not selected, change initial value 0 to 1 (start new increasing partitial sequence)
        maxlen = maxlen < count[i] ? count[i] : maxlen;
    }
    cout << maxlen;
}