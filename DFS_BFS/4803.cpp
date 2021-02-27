/*  BOJ - 4803 : 트리
    27.February.2021
 */

/*  [DFS]
    # 트리 : 정점 n개, 간선 n-1개
      - 정점이 1개인 경우도 트리
    # 방문 노드 체크
    # 한 간선 2번 count : u -> v & v -> u
      -> nodes - 1 == count(edges) / 2
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > trees;
vector<int> check;

int edges = 0;
int nodes = 0;

void dfs(int idx){
    check[idx] = 1;
    nodes++;
    int len = trees[idx].size();
    for(int i = 0; i < len; i++){
        edges++;
        if(!check[trees[idx][i]]){
            dfs(trees[idx][i]);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, u, v;
    int tc = 1;
    while(1){
        cin >> n >> m;
        if(!n && !m) break;
        trees.resize(n + 1, vector<int>(0));
        check.resize(n + 1);
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            trees[u].push_back(v);
            trees[v].push_back(u);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(!check[i]){
                dfs(i);
                if(nodes - 1 == edges / 2) cnt++;
                nodes = 0;
                edges = 0;
            }
        }
        cout << "Case " << tc << ": ";
        if(cnt == 0) cout << "No trees.\n";
        else if(cnt == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << cnt << " trees.\n";
        tc++;
        trees.clear();
        check.clear();
    }
}