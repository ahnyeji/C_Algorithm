/*  BOJ - 2294 : 동전 2
    17.February.2021
 */

/*  [DP]
    # 기저사례
      - won[coins[i]] = 1 : 동전 하나로 만들 수 있는 금액 (동전의 가치와 금액이 같은 경우 필요한 동전 1개)
      - for(i < mini) won[i] = -1 : 가장 작은 동전 가치보다 작은 금액은 항상 만들 수 없음
    # 점화식
      - 가지고 있는 모든 동전에 대해 해당 동전을 1개 사용했을 때 나머지 금액 확인
      - if(won[i - coins[j]] > 0) min(minCnt, won[i - coins[j]] + 1)
        => won[i - coins[j]] > 0 : 나머지 금액을 가지고 있는 동전으로 만들 수 있는 경우
        => min(minCnt, won[i - coins[j]] + 1) : 모든 동전 확인하며 최소 개수로 갱신해야 함
        => minCnt : 정답 범위보다 큰 수로 초기화해야 갱신 가능 (최대 정답 범위는 10000 - 동전 가치 1로 금액 10000 만들 때)
            (이 부분 놓쳐서 오답)
*/

#include <iostream>
#include <vector>

using namespace std;

int coin[100001];
int won[10001];
int main(){
    int n, k;
    cin >> n >> k;

    int c, mini = 100000, maxi = 0; // to check range of coin value
    for(int i = 0; i < n; i++){ // to remove duplicate coins
        cin >> c;
        coin[c]++;
        mini = mini > c ? c : mini;
        maxi = maxi < c ? c : maxi;
    }

    if(mini > k){ // there is no way to make k won (smallest coin > k)
        cout << -1;
        return 0;
    }

    vector<int> coins;
    for(int i = mini; i <= maxi; i++){ // get coins
        if(coin[i]) coins.push_back(i);
    }

    for(int i = 1; i < mini; i++){ // initialize : cannot make prices smaller than mini -> base case
        won[i] = -1;
    }

    int len = coins.size();
    for(int i = 0; i < len; i++){ // initialize : prices that are same with coins to be 1 -> base case
        won[coins[i]] = 1;
    }

    // dp
    for(int i = mini; i <= k; i++){
        if(won[i]) continue; // pass initialized prices
        int minCnt = 10001; // to get minimum count of coins (maximum value that can be answer is 10000 -> need to be bigger than this value)
        for(int j = 0; j < len; j++){ // check all coins
            int idx = i - coins[j]; // using coins[j] -> count(price - coins[j]) + 1
            if(idx > 0 && won[idx] > 0){ // can make (price - coins[j]) with coins
                minCnt = minCnt > won[idx] + 1 ? won[idx] + 1 : minCnt;
            }
        }
        if(minCnt == 10001) won[i] = -1; // cannot make this price with coins (value not updated)
        else won[i] = minCnt;
    }

    cout << won[k];
}