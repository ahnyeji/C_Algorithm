/*  [Dijkstra]
    # O(ElogE) < 16 * 5 * 1e4 = 8 * 1e5
    # Floyd-Warshall : 시간초과
      - O(N^3) = 8 * 1e12
 */

#include <string>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int> > graph(n + 1, vector<int>(0));
    int len = edge.size();
    for(int i = 0; i < len; i++) { // 인접 리스트
        int u = edge[i][0];
        int v = edge[i][1];
        // 양방향 그래프
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> dist(n + 1, INF); // 1번 노드로부터의 거리
    priority_queue<pair<int, int> > pq; // (1번 노드로부터의 거리, 현재 노드)
    dist[1] = 0;
    pq.push(make_pair(0, 1));
    while(!pq.empty()) {
        int c = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        len = graph[u].size();
        for(int i = 0; i < len; i++) {
            int v = graph[u][i];
            if(dist[v] > dist[u] + 1) { // 더 짧은 경로 찾으면 update
                dist[v] = dist[u] + 1;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    int answer = 0;
    int maxi = 0;
    for(int i = 2; i <= n; i++) {
        if(maxi < dist[i]) {
            maxi = dist[i];
            answer = 1;
        }
        else if(maxi == dist[i]) answer++;
    }
    return answer;
}

/*  BFS (모든 간선 비용이 1이므로 가능) - O(V + E) = 7 * 1e4
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int> > graph(n + 1, vector<int>(0));
    int len = edge.size();
    for(int i = 0; i < len; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> visited(n + 1, -1);
    
    queue<int> q;
    q.push(1);
    visited[1] = 0;
    int maxi = 0;
    while(!q.empty()) { // 노드 수만큼 반복 (O(V))
        int u = q.front();
        q.pop();
        
        for(int v : graph[u]) { // 전체적으로는 간선 수만큼 반복 (2*E -> O(E))
            if(visited[v] == -1) {
                visited[v] = visited[u] + 1;
                maxi = maxi < visited[v] ? visited[v] : maxi;
                q.push(v);
            }
        }
    }
    
    int answer = 0;
    for(int i = 2; i <= n; i++) {
        if(maxi == visited[i]) answer++;
    }
    return answer;
}
*/