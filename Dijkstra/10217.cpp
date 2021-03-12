/*  BOJ - 10217 : KCM Travel
    13.March.2021
    (10.March.2021 Live Problem Solving)
 */

/*  [Dijkstra + DP]
    # 뱡향 그래프
    # 다익스트라 알고리즘(distance) + 다이나믹 프로그래밍(cost)
      1. 현재 정점 선택
        - 후보군 중 지금까지 가장 거리(시간)가 작은 정점 (priority queue top())
      2. 현재 정점에 연결된 정점 모두 확인
        - 만약 현재 정점부터 해당 정점까지 비용이 한계 비용(K)보다 크다면 진행 불가 -> continue
        - 만약 현재 정점부터 해당 정점까지 거리가 기존 거리보다 더 작다면
          1) 비용 & 거리 update
          2) update된 비용보다 더 크면서 거리도 더 먼 데이터 불필요 (현재 경로로 왔을 때 더 효율적)
            => 해당 데이터들 모두 update된 거리로 변경
            (*비용이 더 큰데 거리가 같거나 짧을 경우 -> 이후 데이터 모두 거리가 지금보다 짧으므로 update 불필요 : 최적화)
          3) 다음 노드 후보로 추가 (거리와 비용, 해당 정점 priority queue에 삽입)

 */

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int N, M, K;
vector<vector<pair<int, pair<int, int> > > > graph; // {next airport, {cost, distance}}
vector<vector<int> > dist; // [airport][cost] = distance

void dijkstra(){
    dist.assign(N + 1, vector<int>(M + 1, INF)); // initialize all distance INFINITY
    priority_queue<pair<pair<int, int> , int> > pq; // {{-distance, -cost}, airport}
    dist[1][0] = 0;
    pq.push({{0, 0}, 1});

    while(!pq.empty()){
        int d = -pq.top().first.first; // current distance
        int c = -pq.top().first.second; // current cost
        int u = pq.top().second; // current airport
        pq.pop();
        
        if(dist[u][c] < d) continue; // has shorter path
        if(c > M) continue; // cannot go (over budget)

        int len = graph[u].size();
        for(int i = 0; i < len; i++){
            int v = graph[u][i].first; // next airport
            int cost = c + graph[u][i].second.first; // cost from current to next
            int distance = d + graph[u][i].second.second; // distance from current to next

            if(cost > M) continue; // cannot go (over budget)
            if(dist[v][cost] > distance){ // update to shorter distance
                for(int j = cost; j <= M; j++){
                    if(dist[v][j] <= distance) break; // optimization
                    dist[v][j] = distance;
                }
                pq.push({{-distance, -cost}, v});
            }
        }
    }
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cin >> N >> M >> K;
        graph.assign(N + 1, vector<pair<int, pair<int, int> > >());
        int u, v, c, d;
        for(int i = 0; i < K; i++){
            cin >> u >> v >> c >> d;
            graph[u].push_back(make_pair(v, make_pair(c, d)));
        }
        dijkstra();

        int ans = INF;
        for(int i = 1; i <= M; i++){
            ans = ans > dist[N][i] ? dist[N][i] : ans;
        }
        if(ans == INF)
            cout << "Poor KCM\n";
        else cout << ans << "\n";
    }
}