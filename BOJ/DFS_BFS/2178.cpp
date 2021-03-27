/*  BOJ - 2178 : 미로 탐색
    25.February.2021
 */

/*  [DFS / BFS]
    # maze[i][j]
      - 0 : 이동 불가능
      - 1 : 이동 가능
      - > 1 : 현재 칸에 오기까지 이동한 칸 수 + 1 (이동 가능 신호와 구분하기 위해 2부터 시작)
    
    # DFS : 더 느림 (시작 점에서 경로 하나를 선택하여 끝 점까지 가보고 돌아와서 다른 경로 탐색을 시작하기 때문 -> 불가능 경로로 인한 시간 낭비 발생)
      - 현재 칸의 상단 이동 가능 여부 확인 및 이동
        => 이동 가능 하면
            1) 해당 칸의 숫자가 1일 때 : 아직 확인하지 않은 길이므로 update
            2) 해당 칸의 숫자가 현재 칸의 숫자 + 1보다 클 때 : 현재 칸에서 이동하는 경로가 더 짧으므로 update
            -> 현재 칸 + 1로 update
        => 이동
      - 현재 칸의 하단 이동 가능 여부 확인 및 이동
      - 현재 칸의 좌측 이동 가능 여부 확인 및 이동
      - 현재 칸의 우측 이동 가능 여부 확인 및 이동
    
    # BFS : 더 빠름 (시작 점의 주변부터 확인하기 시작하여 끝 점까지 이동하기 때문 -> 불가능 경로로 인한 시간 낭비 최소화)
      - 현재 칸의 상하좌우 이동 가능 여부 확인
        => 이동 가능 하면
            1) 해당 칸의 숫자가 1일 때 : 아직 확인하지 않은 길이므로 update
            2) 해당 칸의 숫자가 현재 칸의 숫자 + 1보다 클 때 : 현재 칸에서 이동하는 경로가 더 짧으므로 update
            -> 현재 칸 + 1로 update
      - 이동
 */

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int maze[100][100]; // 0 : wall, 1 : road, >= 2 : count of spaces to come this space + 1 (start at 2 to distinguish from road)
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right

void bfs(int r, int c){
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
            if((y > -1 && y < N) && (x > -1 && x < M) && (maze[y][x] == 1 || maze[y][x] > maze[r][c] + 1)){
                maze[y][x] = maze[r][c] + 1;
                row.push(y);
                col.push(x);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    string inp;
    for(int i = 0; i < N; i++){
        cin >> inp;
        for(int j = 0; j < M; j++){
            maze[i][j] = inp[j] - '0';
        }
    }

    maze[0][0]++;
    bfs(0, 0);
    
    cout << maze[N - 1][M - 1] - 1;
}

/* DFS ver
#include <iostream>
#include <string>

using namespace std;

int N, M;
int maze[100][100];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int r, int c){
    int y, x;
    for(int i = 0; i < 4; i++){
        y = r + dir[i][0];
        x = c + dir[i][1];
        
        if((y > -1 && y < N) && (x > -1 && x < M) && (maze[y][x] == 1 || maze[y][x] > maze[r][c] + 1)){
            maze[y][x] = maze[r][c] + 1;
            dfs(y, x);
        }
    }
}

int main(){
    cin >> N >> M;
    string inp;
    for(int i = 0; i < N; i++){
        cin >> inp;
        for(int j = 0; j < M; j++){
            maze[i][j] = inp[j] - '0';
        }
    }

    maze[0][0]++;
    dfs(0, 0);
    
    cout << maze[N - 1][M - 1] - 1;
}
*/