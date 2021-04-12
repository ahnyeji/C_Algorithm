#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int len = number.size() - k; // k개 제거 == number.size() - k개 선택
    string answer = "";
    char nowmax;
    int idx = 0;
    for(int i = 0; i < len; i++) {
        nowmax = number[idx];
        for(int j = idx; j <= i + k; j++) {
            if(nowmax < number[j]) {
                nowmax = number[j];
                idx = j;
            }
        }
        answer += nowmax;
        idx++;
    }
    return answer;
}