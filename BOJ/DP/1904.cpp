/*  BOJ - 1904 : 01타일
    13.February.2021

    (13.February.2021 Live Problem Solving)
 */

/*  [DP]
    # 기저사례
      - tile[0] = 0 (사용하지 않는 변수)
      - tile[1] = 1 (1; 00은 두자리이므로 사용 불가)
      - tile[2] = 2 (11, 00)
    # 점화식
      - tile[i] = tile[i - 1] + tile[i - 2]
        => tile[i - 1] : tile[i - 1] 뒤에 1을 덧붙임
        => tile[i - 2] : tile[i - 2] 뒤에 00을 덧붙임

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> tile(N + 1);
    tile[0] = 0;
    tile[1] = 1;
    tile[2] = 2;
    for(int i = 3; i <= N; i++){
        tile[i] = (tile[i - 1] + tile[i - 2]) % 15746;
    }
    cout << tile[N];
}