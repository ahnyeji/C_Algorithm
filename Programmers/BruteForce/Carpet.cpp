#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int tot = brown + yellow;
    for(int h = 1; h * h <= yellow; h++) {
        if(yellow % h > 0) continue;
        int w = yellow / h;
        if((w + 2) * (h + 2) == tot) { // 갈색은 테두리 1줄 -> 상하(2줄), 좌우(2줄)만 추가
            answer.push_back(w + 2);
            answer.push_back(h + 2);
            break;
        }
    }
    return answer;
}