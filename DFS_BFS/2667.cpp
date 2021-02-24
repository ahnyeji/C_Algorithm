/*  BOJ - 2667 : 단지번호붙이기
    24.February.2021
    (24.February.2021 Live Problem Solving)
 */

/*  [DFS]
    # danji[i][j]
      - 1 : 아직 확인하지 않은 집
      - 0 : 집이 아니거나 이미 확인한 집
    # DFS
      - 아직 확인하지 않은 집을 만나면 해당 좌표에서 DFS 시작
      - 상하좌우 확인하며 아직 확인하지 않은 집이 있으면 탐색
        => 이 때 집의 수 더함
      - 주변에 더이상 확인하지 않은 집이 없으면 단지 내 집의 수 return
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char danji[26][26];

int dfs(int row, int col){
    int c = 1;
    danji[row][col] = '0';
    int x, y;
    for(int d = 0; d < 4; d++){
        y = row + dir[d][0];
        x = col + dir[d][1];
        if((y > -1 && y < N) && (x > -1 && x < N) && danji[y][x] == '1'){
            c += dfs(y, x);
            
        }
    }
    return c;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> danji[i];
    }

    vector<int> cnt;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(danji[i][j] == '1'){
                cnt.push_back(dfs(i, j));
            }
        }
    }

    sort(cnt.begin(), cnt.end());

    int len = cnt.size();
    cout << len << "\n";
    for(int i = 0; i < len ;i++){
        cout << cnt[i] << "\n";
    }
}

/* BFS version
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char danji[26][26];

int bfs(int row, int col){
    int c = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(row, col));
    danji[row][col] = '0';
    
    pair<int, int> point;
    while(!q.empty()){
        point = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            row = point.first + dir[i][0];
            col = point.second + dir[i][1];
            if((row > -1 && row < N) && (col > -1 && col < N) && danji[row][col] == '1'){
                q.push(make_pair(row, col));
                danji[row][col] = '0';
                c++;
            }
        }
    }
    return c;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> danji[i];
    }

    vector<int> cnt;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(danji[i][j] == '1'){
                cnt.push_back(bfs(i, j));
            }
        }
    }

    sort(cnt.begin(), cnt.end());

    int len = cnt.size();
    cout << len << "\n";
    for(int i = 0; i < len ;i++){
        cout << cnt[i] << "\n";
    }
}
*/