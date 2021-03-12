/*  BOJ - 1916 : 최소비용 구하기
    13.March.2021
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
#define INF 1e9
using namespace std;

int N, M;
vector<pair<int, int> > graph[1001];
vector<int> dist;

void dijkstra(int start){
    dist.assign(N + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    while(!pq.empty()){
        int c = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        int len = graph[u].size();
        for(int i = 0; i < len; i++){
            int v = graph[u][i].first;
            int cost = c + graph[u][i].second;

            if(dist[v] > cost){
                dist[v] = cost;
                pq.push({-cost, v});
            }
        }
    }
}

int main(){
    cin >> N;
    cin >> M;
    int u, v, c;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
    }
    int A, B;
    cin >> A >> B;
    dijkstra(A);
    cout << dist[B] << "\n";
}