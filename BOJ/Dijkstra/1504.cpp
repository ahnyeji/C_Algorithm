/*  BOJ - 1504 : 특정한 최단경로
    10.March.2021
 */

/*  [Dijkstra]
    # 양뱡향 그래프
    # 특정 정점 지나야 함
      1. 1 -> v1 -> v2 -> N : (1 -> v1) + (v1 -> v2) + (v2 -> N)
      2. 1 -> v2 -> v1 -> N : (1 -> v2) + (v2 -> v1) + (v1 -> N)
      +) v1 -> v2 는 동일 (양방향 그래프이기 때문)
      => 둘 중 최단경로 찾기
    # 다익스트라 알고리즘
      1. 현재 정점 선택
        - 후보군 중 지금까지 가장 비용이 적은 정점 (priority queue top())
      2. 현재 정점에 연결된 정점 모두 확인
        - 만약 현재 정점부터 해당 정점까지 비용이 기존 비용보다 더 작다면
          1) 비용 update
          2) 다음 노드 후보로 추가 (비용과 해당 정점 priority queue에 삽입)
    # 우선순위 큐 사용 시 비용을 음수로 하여 가장 큰 값이 가장 적은 비용이 되도록 하기
      -> 비용으로 사용 시 음수임에 유의하여 사용
 */

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int N, E, v1, v2;
vector<pair<int, int> > graph[801];
vector<int> dist;

void dijkstra(int start){
    dist.assign(N + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});

    while(!pq.empty()){
        int minCost = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        int len = graph[u].size();
        for(int i = 0; i < len; i++){
            int v = graph[u][i].first;
            int cost = graph[u][i].second;

            if(dist[v] > minCost + cost){
                dist[v] = minCost + cost;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    cin >> N >> E;
    
    int a, b, c;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    dijkstra(1);
    int one_v1 = dist[v1];
    int one_v2 = dist[v2];

    dijkstra(v1);
    int v1_v2 = dist[v2];
    int v1_N = dist[N];

    dijkstra(v2);
    int v2_N = dist[N];

    int ans = one_v1 + v2_N < one_v2 + v1_N ? one_v1 + v2_N : one_v2 + v1_N;
    ans += v1_v2;
    if(ans >= INF || ans <= 0){
        cout << "-1\n";
    }
    else cout << ans << "\n";
}