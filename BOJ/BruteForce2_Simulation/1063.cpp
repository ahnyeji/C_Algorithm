#include <iostream>
#include <vector>

using namespace std;

int main(){
    int chess[8][8] = {}; // chess board; King : 1, Stone : 2, blank : 0
    // Directions : R, L, B, T, RT, LT, RB, LB
    int direction[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, 
                     {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};

    string king, stone;
    int kingR, kingC, stoneR, stoneC, N;
    
    cin >> king >> stone >> N;
    
    kingR = 8 - king[1] + '0'; // row input counts up from bottom (opposite to array index)
    kingC = king[0] - 'A';
    stoneR = 8 - stone[1] + '0';
    stoneC = stone[0] - 'A';

    chess[kingR][kingC] = 1; // King
    chess[stoneR][stoneC] = 2; // Stone

    while(N--){
        string move;
        cin >> move;
        
        int dir;
        if(move == "R"){
            dir = 0;
        }
        else if(move == "L"){
            dir = 1;
        }
        else if(move == "B"){
            dir = 2;
        }
        else if(move == "T"){
            dir = 3;
        }
        else if(move == "RT"){
            dir = 4;
        }
        else if(move == "LT"){
            dir = 5;
        }
        else if(move == "RB"){
            dir = 6;
        }
        else if(move == "LB"){
            dir = 7;
        }

        int r = kingR + direction[dir][0]; // row where King to go
        int c = kingC + direction[dir][1]; // column where King to go
        if(r < 0 || r > 7 || c < 0 || c > 7) continue; // out of board -> not move
        if(chess[r][c]){ // Stone exists where King to go
            int sr = r + direction[dir][0];
            int sc = c + direction[dir][1];
            if(sr < 0 || sr > 7 || sc < 0 || sc > 7) continue; // out of board -> not move
            chess[sr][sc] = 2; // move Stone first
            stoneR = sr;
            stoneC = sc;
        }
        chess[r][c] = 1; // move King
        chess[kingR][kingC] = 0; 
        kingR = r;
        kingC = c;
    }
    // 8 - kingR : print with chess row (not array index)
    cout << (char)(kingC + 'A') << 8 - kingR << "\n" << (char)(stoneC + 'A') << 8 - stoneR;
}