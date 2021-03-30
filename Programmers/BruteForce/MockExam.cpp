#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> s1 = {1, 2, 3, 4, 5}; // 학생 1의 패턴
    vector<int> s2 = {2, 1, 2, 3, 2, 4, 2, 5}; // 학생 2의 패턴
    vector<int> s3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 학생 3의 패턴
    
    int len = answers.size();
    vector<int> cnt = {0, 0, 0}; // 학생 1 정답 개수, 학생 2 정답 개수, 학생 3 정답 개수
    int maxi = 0;
    for(int i = 0; i < len; i++) { // 모든 문제 정답 비교
        if(answers[i] == s1[i % 5]) cnt[0]++;
        if(answers[i] == s2[i % 8]) cnt[1]++;
        if(answers[i] == s3[i % 10]) cnt[2]++;
        
        maxi = maxi < cnt[0] ? cnt[0] : maxi;
        maxi = maxi < cnt[1] ? cnt[1] : maxi;
        maxi = maxi < cnt[2] ? cnt[2] : maxi;
    }
    
    vector<int> answer;
    for(int i = 0; i < 3; i++) {
        if(maxi == cnt[i]) answer.push_back(i + 1);
    }
    return answer;
}