/*  BOJ - 7576 : 토마토
    28.February.2021
    (28.February.2021 Live Problem Solving)
 */

/*  [BFS]
    # box[i][j]
      - -1 : 벽 (방문 불가)
      - 0 : 아직 익지 않은 토마토 (방문하지 않은 좌표)
      - > 0 : 해당 좌표의 토마토가 익기까지 걸린 최소 날짜 + 1
      => 최초 시작 토마토가 1인데, 이 경우 0일이므로 모든 토마토가 날짜 + 1 값을 가짐
    # 시작 지점을 미리 queue에 넣어두고 동시에 퍼질 수 있도록 한다
*/

#include <iostream>
#include <queue>
using namespace std;

int M, N;
int box[1000][1000];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pair<int, int> > tomato;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> box[i][j];
            if(box[i][j] == 1){
                tomato.push({i, j});
            }
        }
    }
    int y, x, yy, xx;
    while(!tomato.empty()){
        y = tomato.front().first;
        x = tomato.front().second;
        tomato.pop();
        for(int i = 0; i < 4; i++){
            yy = y + dir[i][0];
            xx = x + dir[i][1];
            if((yy > -1 && yy < N) && (xx > -1 && xx < M) && box[yy][xx] == 0){
                box[yy][xx] = box[y][x] + 1;
                tomato.push({yy, xx});
            }
        }
    }
    int maxi = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(box[i][j] == 0){ // cannot visit this tomato
                cout << -1;
                return 0;
            }
            maxi = maxi < box[i][j] ? box[i][j] : maxi;
        }
    }
    cout << maxi - 1;
}