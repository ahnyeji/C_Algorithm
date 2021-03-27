/*  BOJ - 11726 : 2*n 타일링
    11.February.2021
 */

/*  [DP]
    - tiling[0] = 0 (타일이 없음)
    - tiling[1] = 1 (2*1 타일 1개)
    - tiling[n] = tiling[n - 1] + tiling[n - 2]
        # tiling[n - 1] : tiling[n - 1]에 2*1 타일 1개 붙임
        # tiling[n - 2] : tiling[n - 2]에 1*2 타일 2개 붙임
    
    # 나머지 연산
        - (a + b) % n == (a % n + b % n) % n
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> tiling(n + 1);
    tiling[0] = 1;
    tiling[1] = 1;
    for(int i = 2; i <= n; i++){
        tiling[i] = (tiling[i - 1] + tiling[i - 2]) % 10007; // tiling[i - 1] and tiling[i - 2] already applied modular operation
    }
    cout << tiling[n];
}