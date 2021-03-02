/*  BOJ - 1707 : 이분 그래프
    03.March.2021
 */

/*  [BFS]
    # visit[i]
      - 0 : 아직 방문하지 않은 노드
      - 1 : 그룹 1에 속한 노드 (그룹 1 내의 노드 간에는 간선이 없어야 함)
      - 2 : 그룹 2에 속한 노드 (그룹 2 내의 노드 간에는 간선이 없어야 함)
      
    # BFS
      - 현재 노드의 그룹과 현재 노드에 연결된 노드들의 그룹은 달라야 함 (같은 그룹 내 노드는 간선이 없어야 하기 때문)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
vector<vector<int> > graph;
vector<int> visit; // 0 : not visited yet, 1 : group 1, 2 : group 2

bool bfs(int v){
    int level = 1; // group : 1, 2
    visit[v] = level;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        level = visit[v] == 1 ? 2 : 1;
        int l = graph[v].size();
        for(int i = 0; i < l; i++){
            if(!visit[graph[v][i]]){ // not visited yet -> set group
                visit[graph[v][i]] = level;
                q.push(graph[v][i]);
            }
            else if(visit[graph[v][i]] != level){ // already visited & different group -> cannot be Bipartite Graph
                return false;
            }
        }
    }
    return true;
}

int main(){
    int K, u, v;
    cin >> K;
    while(K--){
        cin >> V >> E;
        graph.assign(V + 1, vector<int>(0));
        visit.assign(V + 1, 0);

        for(int i = 0; i < E; i++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool ans;
        for(int i = 1; i <= V; i++){ // check all graphs
            if(!visit[i]){
                ans = bfs(i);
                if(!ans) break;
            }
        }
        cout << (ans == 1 ? "YES" : "NO") << "\n";
    }
}