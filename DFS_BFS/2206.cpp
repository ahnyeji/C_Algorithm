/*  BOJ - 2206 : 벽 부수고 이동하기
    28.February.2021
 */

/*  [BFS]
    # 가중치 없는 그래프 최단경로 : BFS (DFS는 모든 경로 처음부터 끝까지 가봐야 최단 경로 찾을 수 있음)
    # 모든 벽 하나씩 없애서 BFS 실행하는 방식은 시간초과 (O((NM)^2))
    # 현재 지점에 도달하기까지 아직 벽을 하나도 부수지 않았을 경우 / 벽을 하나 부순 경우 모두 고려
      - map[y][x][0] : 벽을 하나도 부수지 않은 경우
        -> 다음 지점이 벽이 아닌 경우 : map[yy][xx][0] = map[y][x][0] + 1
        -> 다음 지점이 벽인 경우 : map[yy][xx][1] = map[y][x][0] + 1
      - map[y][x][1] : 벽을 이미 부순 경우
        -> 다음 지점이 벽이 아닌 경우 : map[yy][xx][1] = map[y][x] + 1;
        -> 다음 지점이 벽인 경우 : 이동 불가
      - 다음 지점의 map 값이 0이 아닌 경우 : 이미 확인했다면 해당 경로가 최단거리 -> 더 확인할 필요 없음
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
bool graph[1000][1001];
int map[1000][1001][2];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(){
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0, 0), 0));
    map[0][0][0] = 1;

    int y, x, broken, yy, xx;
    while(!q.empty()){
        y = q.front().first.first; // current point's row
        x = q.front().first.second; // current point's column
        broken = q.front().second; // wall broken? 0 : not broken yet, 1 : already broken
        q.pop();
        for(int i = 0; i < 4; i++){
            yy = y + dir[i][0];
            xx = x + dir[i][1];
            if((yy > -1 && yy < N) && (xx > -1 && xx < M)){
                if(graph[yy][xx] && !broken){ // next is wall & not broke any wall -> break
                    map[yy][xx][1] = map[y][x][0] + 1;
                    q.push(make_pair(make_pair(yy, xx), 1));
                }
                if(!graph[yy][xx] && map[yy][xx][broken] == 0){ // next is road & not visited yet -> go
                    map[yy][xx][broken] = map[y][x][broken] + 1;
                    q.push(make_pair(make_pair(yy, xx), broken));
                }
            }
        }
    }
}

int main(){
    cin >> N >> M;
    string inp;
    for(int i = 0; i < N; i++){
        cin >> inp;
        for(int j = 0; j < M; j++){
            graph[i][j] = inp[j] - '0';
        }
    }
    bfs();
    if(map[N - 1][M - 1][0] == 0){
        if(map[N - 1][M - 1][1] == 0){
            cout << -1;
        }
        else {
            cout << map[N - 1][M - 1][1];
        }
    }
    else{
        if(map[N - 1][M - 1][1] == 0){
            cout << map[N - 1][M - 1][0];
        }
        else{
            cout << (map[N - 1][M - 1][0] < map[N - 1][M - 1][1] ? map[N - 1][M - 1][0] : map[N - 1][M - 1][1]);
        }
    }
}