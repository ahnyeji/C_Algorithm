#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int> > dist(N + 1, vector<int> (N + 1, INF)); // dist[f][t] : f < t를 알기 위한 비교 연산 횟수
    
    int f, t;
    while(M--) {
        cin >> f >> t;
        dist[f][t] = 1;
    }
    // Floyd-Warshall
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            if(dist[i][k] == INF) continue;
            for(int j = 1; j <= N; j++) {
                if(dist[k][j] == INF) continue;
                if(dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    // 개수 세기
    for(int i = 1; i <= N; i++) {
        int cnt = 0;
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;
            // dist[i][j]는 i < j 정보만 담고 있음 -> dist[j][i]로 i > j 확인
            if(dist[i][j] == INF && dist[j][i] == INF) cnt++;
        }
        cout << cnt << "\n";
    }
}