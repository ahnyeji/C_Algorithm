/*  BOJ - 1753 : 최단경로
    10.March.2021
 */

/*  [Dijkstra]
    # 뱡향 그래프
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
#define INF 1e9 // 10^9
using namespace std;

int V, E, K;
vector<pair<int, int> > graph[20001];
vector<int> dist;

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<pair<int, int> > pq; // to get minimum cost destination from current vertex
    pq.push({0, start}); // starting point cost : 0, starting point vertex : start

    while(!pq.empty()){
        int minCost = -pq.top().first; // to use priority queue easier, saved cost as negative num (pq's top : largest num)
        int u = pq.top().second;
        pq.pop();

        int len = graph[u].size(); // count vertices connected to current vertex
        for(int i = 0; i < len; i++){
            int v = graph[u][i].first;
            int cost = graph[u][i].second;

            if(dist[v] > minCost + cost){
                dist[v] = minCost + cost;
                pq.push({-dist[v], v}); // save cost as negative number
            }
        }
    }
}

int main(){
    cin >> V >> E;
    cin >> K;

    int u, v, cost;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost}); // directed graph
    }
    
    dist.assign(V + 1, INF); // initialize

    dijkstra(K);

    for(int i = 1; i <= V; i++){
        if(dist[i] == INF){
            cout << "INF\n";
        }
        else cout << dist[i] << "\n";
    }
}