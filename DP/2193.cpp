/*  BOJ - 2193 : 이친수
    12.February.2021
 */

/*  [DP]
    - pinary[0] = 0 (해당하는 이친수 없음)
    - pinary[1] = 1 (1; 1로 시작해야하므로 0은 불가)
    - pinary[i] = pinary[i - 1] + pinary[i - 2]
        # pinary[i - 1] : pinary[i - 1] 뒤에 0을 덧붙임 (-> 0으로 끝나는 경우; 11을 부분 문자열로 갖지 않기 위함)
        # pinary[i - 2] : pinary[i - 2] 뒤에 01을 덧붙임 (-> 1로 끝나는 경우; 11을 부분 문자열로 갖지 않기 위함)

    # int형으로 계산할 경우 overflow 발생하므로 long long형 연산 필요
        (N > 46인 경우에 발생)
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> pinary(N + 1);
    pinary[0] = 0;
    pinary[1] = 1;
    for(int i = 2; i <= N; i++){
        pinary[i] = pinary[i - 1] + pinary[i - 2];
    }
    cout << pinary[N];
}