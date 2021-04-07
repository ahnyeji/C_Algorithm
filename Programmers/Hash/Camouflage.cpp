#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> ctype;
    int len = clothes.size();
    for(int i = 0; i < len; i++) {
        ctype[clothes[i][1]]++;
    }
    
    int answer = 1;
    for(auto c : ctype) {
        answer *= (c.second) + 1; // 현재 카테고리에서 아무 것도 뽑지 않는 경우까지 포함
    }
    return answer - 1; // 전체 카테고리에서 아무 것도 뽑지 않는 경우는 제외
}