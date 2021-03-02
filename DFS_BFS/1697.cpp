/*  BOJ - 1697 : 숨바꼭질
    28.February.2021
    (28.February.2021 Live Problem Solving)
 */

/*  [BFS]
    # N >= K : 무조건 -1 이동만 가능하기 때문에 수학 연산만으로 답 도출 가능
    # visit[i]
      - 0 : 아직 방문하지 않은 점
      - > 0 : 점 i에 방문하기까지 이동한 횟수

    # BFS
      - i * 2 : 0 <= i * 2 < K + 2 -> K + 2가 된다면 (i - 1) * 2가 i * 2 - 1 - 1보다 빠름
      - i + 1 : i + 1 <= K -> K보다 커지면 -1 이동을 해야하므로 불필요한 이동 발생
      - i - 1 : i - 1 >= 0 -> 0까지가 점의 범위
 */

#include <iostream>
#include <queue>

using namespace std;

int N, K;
int visit[100001];

int main(){
    cin >> N >> K;

    if(N >= K){
        cout << N - K;
        return 0;
    }

    queue<int> q;
    q.push(N);
    int curr;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr == K) break;
        
        if(curr > 0 && curr * 2 < K + 2 && visit[curr * 2] == 0){
            visit[curr * 2] = visit[curr] + 1;
            q.push(curr * 2);
        }
        if(curr + 1 <= K && visit[curr + 1] == 0){
            visit[curr + 1] = visit[curr] + 1;
            q.push(curr + 1);
        }
        if(curr - 1 >= 0 && visit[curr - 1] == 0){
            visit[curr - 1] = visit[curr] + 1;
            q.push(curr - 1);
        }
    }
    cout << visit[K];
}