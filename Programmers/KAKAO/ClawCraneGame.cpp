#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int len = board.size();
    vector<int> floor(len, 0);
    for(int j = 0; j < len; j++) {
        int idx = floor[j];
        while(idx < len && board[idx][j] == 0) idx++;
        floor[j] = idx;
    }
    
    stack<int> basket;
    int answer = 0;
    for(int j : moves) {
        j--;
        if(floor[j] == len) continue;
        int i = floor[j];
        if(basket.empty() || basket.top() != board[i][j]) basket.push(board[i][j]);
        else {
            answer += 2;
            basket.pop();
        }
        floor[j]++;
    }
    return answer;
}