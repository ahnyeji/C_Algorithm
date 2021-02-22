/*  BOJ - 17406 : 배열 돌리기 4
    20.February.2021
    (20.February.2021 Live Problem Solving)
 */

/*  [BruteForce]
    # 순열 : 회전 순서
    [Simulation]
    # 회전
 */

#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int r[6], c[6], s[6];
int visit[6];
int minVal = 5000;

vector<vector<int> > rotate(int r, int c, int s, vector<vector<int> > a){
    for(int sr = r - s, sc = c - s, er = r + s, ec = c + s; sr < r; sr++, sc++, er--, ec--){
        int start = a[sr][sc]; // This element overwritten by below -> need to save
        // moving left column : upward (under element -> current element)
        for(int row = sr; row < er; row++){
            a[row][sc] = a[row + 1][sc];
        }
        // moving lower row : left (right element -> current element)
        for(int col = sc; col < ec; col++){
            a[er][col] = a[er][col + 1];
        }
        // moving right column : downward (above element -> current element)
        for(int row = er; row > sr; row--){
            a[row][ec] = a[row - 1][ec];
        }
        // moving upper row : right (left element -> current element)
        for(int col = ec; col > sc; col--){
            a[sr][col] = a[sr][col - 1];
        }
        a[sr][sc + 1] = start; // make overwritten value original value
    }
    return a;
}

int getArrayVal(vector<vector<int> > a){ // calculate Array Value (minimum row sum)
    int minsum = 5000;
    for(int i = 1; i <= N; i++){
        int sum = 0;
        for(int j = 1; j <= M; j++){
            sum += a[i][j];
        }
        minsum = minsum > sum ? sum : minsum;
    }
    return minsum;
}

void perm(int cnt, vector<vector<int> > a){ // make rotation order -> permutation
    if(cnt == K) {
        int val = getArrayVal(a);
        minVal = minVal > val ? val : minVal;
        return;
    }
    for(int i = 0; i < K; i++){
        if(!visit[i]){
            visit[i] = 1;
            perm(cnt + 1, rotate(r[i], c[i], s[i], a));
            visit[i] = 0;
        }
    }
}

int main(){
    cin >> N >> M >> K;

    vector<vector<int> > A(N + 1, vector<int>(M + 1));

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < K; i++){
        cin >> r[i] >> c[i] >> s[i];
    }

    perm(0, A);
    
    cout << minVal << "\n";
}