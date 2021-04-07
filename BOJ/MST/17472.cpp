#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int map[11][11];
int p[7];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

// numbering islands
void bfs(int r, int c, int idx) {
    queue<pair<int, int>> q;
    q.push({r, c});
    map[r][c] = idx;
    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int y = r + dy[i];
            if(y < 0 || y >= N) continue;
            int x = c + dx[i];
            if(x < 0 || x >= M) continue;
            if(map[y][x] == -1) {
                map[y][x] = idx;
                q.push({y, x});
            }
        }
    }
}

// Union-Find : Find
int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]); // path compression
}

// Union-Find : Union
void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return;
    p[y] = x;
}

int main() {
    cin >> N >> M;

    int inp;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> inp;
            map[i][j] = -inp;
        }
    }

    int idx = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == -1) bfs(i, j, idx++);
        }
    }

    int len = idx;
    for(int i = 1; i <= len; i++) p[i] = i; // Union-Find : makeset
    
    // Kruskal : make edges
    priority_queue<pair<int, pair<int, int>>> pq;
    
    for(int i = 0; i < N; i++) { // vertical
        idx = 0; int c = 0;
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 0) continue;
            if(idx == map[i][j]) c = j;
            else {
                int diff = j - c - 1;
                if(idx > 0 && diff > 1) {
                    pq.push({-diff, {idx, map[i][j]}});
                    pq.push({-diff, {map[i][j], idx}});
                }
                idx = map[i][j];
                c = j;
            }
        }
    }

    for(int j = 0; j < M; j++) { // horizontal
        idx = 0; int r = 0;
        for(int i = 0; i < N; i++) {
            if(map[i][j] == 0) continue;
            if(idx == map[i][j]) r = i;
            else {
                int diff = i - r - 1;
                if(idx > 0 && diff > 1) {
                    pq.push({-diff, {idx, map[i][j]}});
                    pq.push({-diff, {map[i][j], idx}});
                }
                idx = map[i][j];
                r = i;
            }
        }
    }
    
    // Kruskal
    int ans = 0;
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();
        
        if(find(u) == find(v)) continue;
        ans += cost;
        merge(u, v);
    }
    int cnt = 0;
    for(int i = 1; i < len; i++) {
        if(i == p[i]) cnt++;
    }
    if(cnt > 1) ans = -1;
    cout << ans << "\n";
}