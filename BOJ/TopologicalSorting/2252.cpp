#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1); // 현재 정점으로 들어오는 간선 수 -> 진입 차수
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        indegree[B]++;
    }

    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) q.push(i); // 진입 차수가 0인 노드를 큐에 삽입
    }

    vector<int> answer;
    for(int i = 1; i <= N; i++) {
        int now = q.front();
        q.pop();

        answer.push_back(now);
        for(int next : graph[now]) {
            indegree[next]--; // 연결 간선 제거
            if(indegree[next] == 0) q.push(next); // 진입 차수가 0인 노드 큐에 삽입
        }
    }

    for(int n : answer) {
        cout << n << " ";
    }
}