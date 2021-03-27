/*  BOJ - 11399 : ATM
    04.March.2021
 */

/*  [Greedy]
    # 인출 시간이 가장 적은 사람을 먼저 택하는 것이 탐욕적
      - 가장 앞 사람의 인출 시간이 계산에 N번 포함됨
      - 그 다음 사람의 인출 시간은 계산에 N-1번 포함됨
                            .
                            .
                            .
      - 가장 마지막 사람의 인출 시간은 계산에 1번 포함됨
    => 인출 시간이 적은 순서로 정렬
 */

#include <iostream>
#include <algorithm>

using namespace std;

int P[1000];

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }

    sort(P, P + N);
    
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += P[i] * (N - i);
    }

    cout << sum;
}