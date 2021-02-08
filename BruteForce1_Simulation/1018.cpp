#include <iostream>
#include <vector>
using namespace std;

vector<string> chess = {    "WBWBWBWB",
                            "BWBWBWBW",
                            "WBWBWBWB",
                            "BWBWBWBW",
                            "WBWBWBWB",
                            "BWBWBWBW",
                            "WBWBWBWB",
                            "BWBWBWBW"  };

int main(){
    int N, M;
    cin >> N >> M;

    vector<string> board(N);

    int rows = N - 7;
    int cols = M - 7;

    for(int i = 0; i < N; i++){
        cin >> board[i];
    }

    int min = 2500;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int diff = 0;
            for(int r = 0; r < 8; r++){
                for(int c = 0; c < 8; c++){
                    if(board[i + r][j + c] != chess[r][c]){
                        diff++;
                    }
                }
            }
            diff = diff > (64 - diff) ? 64 - diff : diff;
            min = min > diff ? diff : min;
        }
    }
    cout << min;
}