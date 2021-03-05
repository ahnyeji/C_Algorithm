/*  BOJ - 1920 : 중량제한
    06.March.2021
 */

/*  [Binary Search]
    # 옮길 수 있는 중량을 lo, hi, mid 설정
    # 중량이 mid일 때 다리를 건널 수 있는 지 bfs로 탐색
      - true : 더 큰 중량 탐색 (최대 중량을 찾아야 하므로; lo = mid + 1)
      - false : 더 작은 중량 탐색 (다리를 건널 수 없으므로 더 작은 중량에서 찾아야 함; hi = mid - 1)
    # 메모리 초과
      - 10001 * 10001 int형 인접행렬 : 10001 * 10001 * 4byte > 400000000byte = 400000KB = 400MB > 128MB
      => 인접리스트 사용해야 함
 */

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N, M, u, v, w;
vector<vector<pair<int, int> > > graph;
bool visit[10001];

bool bfs(int maxW){
    visit[u] = 1;
    queue<int> q;
    q.push(u);
    int from, to, len;
    while(!q.empty()){
        from = q.front();
        q.pop();
        if(from == v) return true;
        len = graph[from].size();
        for(int i = 0; i < len; i++){
            to = graph[from][i].first;
            if(!visit[to] && graph[from][i].second >= maxW){
                visit[to] = 1;
                q.push(to);
            }
        }
    }
    return false;
}

int main(){
    cin >> N >> M;
    graph.assign(N + 1, vector<pair<int, int> >(0));
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cin >> u >> v;

    int lo = 1;
    int hi = 1000000000;
    int mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;    
        memset(visit, 0, sizeof(visit));

        if(bfs(mid)){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << hi;
}