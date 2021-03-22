#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

void bfs(int start, int n, vector<vector<int>> computers) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(computers[now][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.assign(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]) {
            bfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}