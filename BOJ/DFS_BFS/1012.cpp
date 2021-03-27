/*  BOJ - 1012 : 유기농 배추
    25.February.2021
 */

/*  [DFS / BFS]
    # ground[i][j]
      - 0 : 배추 없음
      - 1 : 배추 있음
    
    # DFS / BFS
      - 탐색한 장소는 0으로 처리 (더 이상 값이 필요하지 않기 때문)
 */

#include <iostream>

using namespace std;

int N, M, K;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
bool ground[50][50];

void dfs(int r, int c){ // find adjacent cabbage
    ground[r][c] = 0;
    int y, x;
    for(int i = 0; i < 4; i++){
        y = r + dir[i][0];
        x = c + dir[i][1];
        if((y > -1 && y < N) && (x > -1 && x < M) && ground[y][x]){
            dfs(y, x);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T, x, y;
    cin >> T;
    while(T--){
        cin >> M >> N >> K;

        for(int i = 0; i < K; i++){
            cin >> x >> y;
            ground[y][x] = 1;
        }
        
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(ground[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}

/*
#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
bool ground[50][50];

void bfs(int r, int c){ // find adjacent cabbage
    ground[r][c] = 0;
    int y, x;

    queue<int> row;
    queue<int> col;
    row.push(r);
    col.push(c);

    while(!row.empty()){
        r = row.front();
        c = col.front();
        row.pop(); col.pop();
        for(int i = 0; i < 4; i++){
            y = r + dir[i][0];
            x = c + dir[i][1];
            if((y > -1 && y < N) && (x > -1 && x < M) && ground[y][x]){
                ground[y][x] = 0;
                row.push(y);
                col.push(x);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T, x, y;
    cin >> T;
    while(T--){
        cin >> M >> N >> K;

        for(int i = 0; i < K; i++){
            cin >> x >> y;
            ground[y][x] = 1;
        }
        
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(ground[i][j]){
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}
*/