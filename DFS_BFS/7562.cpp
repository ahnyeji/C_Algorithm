/*  BOJ - 7562 : 나이트의 이동
    28.February.2021
    (28.February.2021 Live Problem Solving)
 */

/*  [BFS]
    # 8방 탐색
    # visit[i][j] : 해당 위치에 오기까지 이동한 횟수
    # 목표 지점 좌표가 최초 등장할 경우가 최소 이동 횟수 (BFS)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int I, dest_x, dest_y;
int dir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
vector<vector<int> > chess;

int bfs(int y, int x){
    int yy, xx;
    queue<pair<int, int> > q;
    q.push({y, x});
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        if(y == dest_y && x == dest_x){
            return chess[y][x];
        }
        for(int i = 0; i < 8; i++){
            yy = y + dir[i][0];
            xx = x + dir[i][1];
            if((yy > -1 && yy < I) && (xx > -1 && xx < I) && chess[yy][xx] == 0){
                chess[yy][xx] = chess[y][x] + 1;
                q.push({yy, xx});
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t, curr_x, curr_y;
    cin >> t;
    while(t--){
        cin >> I;
        cin >> curr_y >> curr_x;
        cin >> dest_y >> dest_x;
        chess.assign(I, vector<int>(I));
        cout << bfs(curr_y, curr_x) << "\n";
    }
}