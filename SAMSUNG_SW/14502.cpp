/*  BOJ - 14502 : 연구소
    16.March.2021
 */

/*  [완전탐색(조합) + BFS]
    # 조합(combination)
      - 벽 3개를 세우는 경우의 수를 조합으로 찾기 (벽을 세우는 순서는 상관 없으므로 순열x)
    # BFS
      - 벽 3개를 세운 후 바이러스를 퍼뜨려 안전 영역을 찾기 위함
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int origin[8][8];
int wall[3][2];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int> > spaces; // candidate to make wall
int len; // size of candidate
int maxi = 0; // maximum safe zone size
void bfs(queue<pair<int, int> > q){
    // make map with new 3 walls
    int map[8][8];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map[i][j] = origin[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        map[wall[i][0]][wall[i][1]] = 1;
    }

    // spreading virus
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int y = r + dir[i][0];
            int x = c + dir[i][1];
            if((y > -1 && y < N) && (x > -1 && x < M) && map[y][x] == 0){
                map[y][x] = 2;
                q.push({y, x});
            }
        }
    }
    // count safe zone
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){
                cnt++;
            }
        }
    }
    maxi = maxi < cnt ? cnt : maxi;
}

void makeWall(int cnt, int idx, queue<pair<int, int> > v){ // combination : select 3 walls
    if(cnt == 3){ // select all walls
        bfs(v);
        return;
    }
    for(int i = idx; i < len; i++){
        wall[cnt][0] = spaces[i].first;
        wall[cnt][1] = spaces[i].second;
        makeWall(cnt + 1, i + 1, v);
    }
}

int main(){
    cin >> N >> M;
    queue<pair<int, int> > virus;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> origin[i][j];
            switch(origin[i][j]){
                case 0:
                    spaces.push_back({i, j}); // candidates of walls
                    break;
                case 2:
                    virus.push({i, j}); // starting points of spreading virus
                    break;
                default:
                    break;
            }
        }
    }
    len = spaces.size();
    makeWall(0, 0, virus);
    cout << maxi << "\n";
}