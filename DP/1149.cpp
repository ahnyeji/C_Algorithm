/*  BOJ - 1149 : RGB거리
    13.February.2021

    (13.February.2021 Live Problem Solving)
 */

/*  [DP]
    # 기저사례
      - price[0][0] = color[0][0] : 0번째 집을 빨간색으로 칠할 경우
      - price[0][1] = color[0][1] : 0번째 집을 초록색으로 칠할 경우
      - price[0][2] = color[0][2] : 0번째 집을 파란색으로 칠할 경우
    # 점화식
      - price[i][0] = color[i][0] + min(price[i - 1][1], price[i - 1][2]) : i번째 집을 빨간색으로 칠할 경우의 최소비용
        => 이전 집을 초록색으로 칠했거나 파란색으로 칠했을 경우에만 가능
      - price[i][1] = color[i][1] + min(price[i - 1][0], price[i - 1][2]) : i번째 집을 초록색으로 칠할 경우의 최소비용
        => 이전 집을 빨간색으로 칠했거나 파란색으로 칠했을 경우에만 가능
      - price[i][2] = color[i][2] + min(price[i - 1][0], price[i - 1][2]) : i번째 집을 파란색으로 칠할 경우의 최소비용
        => 이전 집을 빨간색으로 칠했거나 초록색으로 칠했을 경우에만 가능
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int color[1000][3];
    int price[1000][3];
    for(int i = 0; i < N; i++){
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }
    price[0][0] = color[0][0];
    price[0][1] = color[0][1];
    price[0][2] = color[0][2];

    for(int i = 1; i < N; i++){
        price[i][0] = color[i][0] + min(price[i - 1][1], price[i - 1][2]);
        price[i][1] = color[i][1] + min(price[i - 1][0], price[i - 1][2]);
        price[i][2] = color[i][2] + min(price[i - 1][0], price[i - 1][1]);
    }
    cout << min(min(price[N - 1][0], price[N - 1][1]), price[N - 1][2]);
}