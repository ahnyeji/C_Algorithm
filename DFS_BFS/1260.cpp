#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int> > graph;
vector<bool> visit;

void dfs(int v) {
	cout << v << " ";
	visit[v] = 1;
    int len = graph[v].size();
    for(int i = 0; i < len; i++){
        if(visit[graph[v][i]] == 0){
            dfs(graph[v][i]);
        }
    }
}

void bfs(int v) {
	queue<int> q;
	visit[v] = 1;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		cout << v << " ";
		q.pop();

        int len = graph[v].size();
        for(int i = 0; i < len; i++){
            if(visit[graph[v][i]] == 0) {
                visit[graph[v][i]] = 1;
                q.push(graph[v][i]);
            }
        }
	}
}

int main() {
	cin >> N >> M >> V;

    graph.resize(N + 1, vector<int>(0));

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
        // undirected graph : add both
        graph[u].push_back(v);
        graph[v].push_back(u);
	}
    for(int i = 1; i <= N; i++){ // to visit node ascending order
        if(!graph[i].empty()){
            sort(graph[i].begin(), graph[i].end());
        }
    }
    // initialize visit vector
    visit.resize(N + 1, 0);
	dfs(V);
	cout << "\n";
    // initialize visit vector
    visit.clear();
    visit.resize(N + 1, 0);
	bfs(V);
}