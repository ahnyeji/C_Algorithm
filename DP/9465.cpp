/*  BOJ - 9465 : 스티커
    12.February.2021
 */

/*  [DP]
    # 기저사례
      - ans[0][0] = sticker[0][0] : 0번째 열의 위쪽 스티커를 선택한 경우
      - ans[1][0] = sticker[1][0] : 0번째 열의 아래쪽 스티커를 선택한 경우
    # 점화식
      - ans[0][i] = sticker[0][i] + max(ans[1][i - 1], ans[2][i - 1]) : i번째 열의 위쪽 스티커를 선택한 경우의 최대값
        => 이전 열에서 아래쪽 스티커를 선택했거나 아무 스티커도 선택하지 않았을 경우에만 가능
      - ans[1][i] = sticker[1][i] + max(ans[0][i - 1], ans[2][i - 1]) : i번째 열의 아래쪽 스티커를 선택한 경우의 최대값
        => 이전 열에서 위쪽 스티커를 선택했거나 아무 스티커도 선택하지 않았을 경우에만 가능
      - ans[2][i] = max(ans[0][i - 1], ans[1][i - 1]) : i번째 열의 스티커를 선택하지 않은 경우
        => 이전 열의 선택과 무관(최대값만 찾으면 됨)
*/

#include <iostream>
#include <vector>

using namespace std;

int sticker[2][100000];
int ans[3][100000];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T, n;
    
    cin >> T;
    while(T--){
        cin >> n;
        
        for(int i = 0; i < n; i++){
            cin >> sticker[0][i];
        }
        for(int i = 0; i < n; i++){
            cin >> sticker[1][i];
        }

        ans[0][0] = sticker[0][0];
        ans[1][0] = sticker[1][0];
        ans[2][0] = 0;
        for(int i = 1; i < n; i++){
            ans[0][i] = sticker[0][i] + max(ans[1][i - 1], ans[2][i - 1]);
            ans[1][i] = sticker[1][i] + max(ans[0][i - 1], ans[2][i - 1]);
            ans[2][i] = max(ans[0][i - 1], ans[1][i - 1]);
        }
        cout << max(max(ans[0][n - 1], ans[1][n - 1]), ans[2][n - 1]) << "\n";
    }