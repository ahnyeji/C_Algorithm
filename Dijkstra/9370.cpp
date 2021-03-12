/*  BOJ - 9370 : 미확인 도착지
    10.March.2021
    (10.March.2021 Live Problem Solving)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m, t;
int s, g, h;
vector<vector<pair<int, int> > > graph;
vector<int> dist;

void dijkstra(int start){
    dist.assign(n + 1, INF);
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
            int cost = graph[u][i].second;

            if(dist[v] > c + cost){
                dist[v] = c + cost;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        
        graph.assign(n + 1, vector<pair<int, int> >());
        int a, b, d;
        for(int i = 0; i < m; i++){
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }

        vector<int> dlist;
        int dest;
        for(int i = 0; i < t; i++){
            cin >> dest;
            dlist.push_back(dest);
        }
        sort(dlist.begin(), dlist.end());

        dijkstra(s);
        vector<pair<int, int> > directMin;
        for(int i = 0; i < t; i++){
            directMin.push_back({dlist[i], dist[dlist[i]]});
        }

        int sTOg = dist[g];
        int sTOh = dist[h];
        dijkstra(g);
        int gTOh = dist[h];
        vector<pair<int, int> > passMin;
        for(int i = 0; i < t; i++){
            passMin.push_back({dlist[i], sTOh + dist[dlist[i]]});
        }
        dijkstra(h);
        for(int i = 0; i < t; i++){
            passMin[i].second = passMin[i].second < sTOg + dist[dlist[i]] ? passMin[i].second : sTOg + dist[dlist[i]];
            passMin[i].second += gTOh;

            if(directMin[i].second == passMin[i].second && directMin[i].second < INF){
                cout << directMin[i].first << " ";
            }
        }
        cout << "\n";
    }
}