#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map(n, vector<int>(m));
    for(auto p : puddles) {
        map[p[1] - 1][p[0] - 1] = -1; // 웅덩이 (m, n) 형태로 주어지는 것에 유의!
    }
    int idx = 0;
    while(idx < m && map[0][idx] != -1) map[0][idx++] = 1; // 위쪽 테두리 초기화
    idx = 1;
    while(idx < n && map[idx][0] != -1) map[idx++][0] = 1; // 왼쪽 테두리 초기화
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(map[i][j] == -1) continue;
            if(map[i - 1][j] != -1) map[i][j] += map[i - 1][j];
            if(map[i][j - 1] != -1) map[i][j] = (map[i][j] + map[i][j - 1]) % 1000000007;
        }
    }
    return map[n - 1][m - 1];
}