/*  BOJ - 9095 : 1, 2, 3 더하기
    15.February.2021
 */

/*  [DP]
    # 기저사례
      - num[0] = 1 : 아무 숫자도 선택하지 않는 경우
      - num[1] = 1 : 1
      - num[2] = 2 : {1+1}, {2(0+2)}
    # 점화식
      - num[i] = num[i - 1] + num[i - 2] + num[i - 3];
        => num[i - 1] : (i - 1) + 1
        => num[i - 2] : (i - 2) + 2
        => num[i - 3] : (i - 3) + 3

*/

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num[11] = {};
    num[0] = 1;
    num[1] = 1;
    num[2] = 2;
    for(int i = 3; i < 11; i++){
        num[i] = num[i - 1] + num[i - 2] + num[i - 3];
    }

    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        cout << num[n] << "\n";
    }
}