/*  [Floyd-Warshall]
    - BOJ 10159 저울 문제와 유사
 */

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> win(n + 1, vector<bool>(n + 1, false));
    int len = results.size();
    for(int i = 0; i < len; i++) {
        win[results[i][0]][results[i][1]] = true;
    }
    
    // Floyd-Warshall
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            if(k == i || !win[i][k]) continue;
            for(int j = 1; j <= n; j++) {
                if(k == j || !win[k][j] || win[i][j]) continue;
                win[i][j] = true;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int cnt = 1; // to contain i == j (always false)
        for(int j = 1; j <= n; j++) {
            if(win[i][j] || win[j][i]) cnt++; // win[i][j] : i win j or win[j][i] i lose to j
        }
        if(cnt == n) answer++;
    }
    return answer;
}