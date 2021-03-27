/*  BOJ - 2606 : 바이러스
    24.February.2021
    (24.February.2021 Live Problem Solving)
 */

/*  [BFS]
    # computers : 그래프
    # visit : 노드 방문 여부 기록
    # BFS
      - node 1부터 시작하여 연결된 노드 모두 enqueue & 방문 처리
      - queue 빌 때까지 dequeue + 연결 노드 enqueue & 방문 처리 반복
        => 연결된 노드 모두 탐색 완료
      - 방문 처리된 노드가 바이러스에 감염된 컴퓨터
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, edges;
vector<vector<int> > computers;
vector<int> visit;

int main(){
    cin >> n;
    cin >> edges;
    
    computers.resize(n + 1, vector<int>(0));
    visit.resize(n + 1, 0);

    int u, v;
    for(int i = 0; i < edges; i++){ // graph
        cin >> u >> v;
        computers[u].push_back(v);
        computers[v].push_back(u);
    }

    // BFS
    queue<int> q;
    q.push(1);
    visit[1] = 1;
    int node;
    while(!q.empty()){
        node = q.front();
        q.pop();
        int len = computers[node].size();
        for(int i = 0; i < len; i++){
            if(!visit[computers[node][i]]){
                q.push(computers[node][i]);
                visit[computers[node][i]] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(visit[i]) cnt++;
    }
    cout << cnt;
}