#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int len = name.length();
    if(len == 1) {
        int diff = name[0] = 'A';
        return diff < 26 - diff ? diff : 26 - diff;
    }
    vector<int> fromA(len, 0);
    for(int i = 0; i < len; i++) {
        int diff = name[i] - 'A';
        fromA[i] = diff < 26 - diff ? diff : 26 - diff;
    }
    int answer = 0;
    int idx = 0;
    int right = 0;
    int left = 0;
    while(true) {
        answer += fromA[idx];
        fromA[idx] = 0;
        
        while(right < len && fromA[(idx + right) % len] == 0) right++;
        while(left < len && fromA[(idx - left + len) % len] == 0) left++;
        if(right == len) break; // 이미 완성됨 -> 종료
        if(left < right) { // 이동 거리가 더 짧은 쪽으로 이동
            idx = (idx - left + len) % len;
            answer += left;
        }
        else {
            idx = (idx + right) % len;
            answer += right;
        }
        right = 0;
        left = 0;
    }
    return answer;
}