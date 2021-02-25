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