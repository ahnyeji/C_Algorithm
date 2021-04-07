#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> leftday;
    int len = progresses.size();
    for(int i = 0; i < len; i++) { // 남은 날짜 계산
        int left = 100 - progresses[i];
        if(left % speeds[i] != 0) leftday.push(left / speeds[i] + 1);
        else leftday.push(left / speeds[i]);
    }
    vector<int> answer;
    int cnt = 1;
    int t = leftday.front();
    leftday.pop();
    while(!leftday.empty()) {
        if(t < leftday.front()) { // 현재가 다음 기능 개발 종료일보다 빠르면 따로 배포
            answer.push_back(cnt);
            cnt = 1;
            t = leftday.front();
        }
        else cnt++; // 현재가 다음 기능 개발 종료일보다 늦으면 다음 기능과 함께 배포
        leftday.pop();
    }
    answer.push_back(cnt); // 마지막 배포
    return answer;
}