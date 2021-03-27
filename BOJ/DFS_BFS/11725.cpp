/*  BOJ - 11725 : 트리의 부모 찾기
    19.February.2021
 */

/*  [BFS]
    # root부터 bfs로 탐색하면 모든 노드의 부모 찾을 수 있음
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int> > g(N + 1, vector<int>(0));
    vector<int> check(N + 1);

    int u, v;
    for(int i = 1; i < N; i++){ // make undirected graph (tree)
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // bfs
    int len, p;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        p = q.front();
        q.pop();
        len = g[p].size();
        for(int i = 0; i < len; i++){
            if(check[g[p][i]] == 0){
                check[g[p][i]] = p;
                q.push(g[p][i]);
            }
        }
    }

    for(int i = 2; i <= N; i++){
        cout << check[i] << "\n";
    }
}