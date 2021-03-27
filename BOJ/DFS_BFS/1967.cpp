/*  BOJ - 1967 : 트리의 지름
    28.February.2021
 */

/*  [DFS]
    # 지름의 양 끝점
      - 임의의 노드에서 가중치 합이 가장 큰 곳에 위치한 노드 (편의상 루트 노드에서 찾기)
      - 위에서 찾은 노드에서 가중치 합이 가장 큰 곳에 위치한 노드

 */

#include <iostream>
#include <vector>

using namespace std;

int n, maxLen, maxNode;
vector<vector<pair<int, int> > > tree;
vector<bool> visit;

void dfs(int node, int len){
    if(len > maxLen){ // to find logest path from start node
        maxLen = len;
        maxNode = node;
    }
    visit[node] = 1;
    int l = tree[node].size();
    for(int i = 0; i < l; i++){
        if(!visit[tree[node][i].first]){
            visit[tree[node][i].first] = 1;
            dfs(tree[node][i].first, len + tree[node][i].second);
        }
    }
}

int main(){
    cin >> n;
    tree.resize(n + 1, vector<pair<int, int> >(0));
    visit.resize(n + 1, 0);
    int u, v, cost;
    for(int i = 1; i < n; i++){
        cin >> u >> v >> cost;
        tree[u].push_back(make_pair(v, cost));
        tree[v].push_back(make_pair(u, cost));
    }
    dfs(1, 0); // find logest node from root
    visit.clear();
    maxLen = 0;
    visit.resize(n + 1, 0);
    dfs(maxNode, 0); // find tree's longest diameter
    cout << maxLen;
}