#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    vector<int> clothes(n + 1, 1); // 1 : 체육복 있는 학생, 2 : 여벌 체육복 있는 학생, 0 : 체육복 없는 학생
    int len = lost.size();
    for(int i = 0; i < len; i++) clothes[lost[i]]--;
    
    len = reserve.size();
    for(int i = 0; i < len; i++) clothes[reserve[i]]++;
    
    for(int i = 1; i < n; i++) {
        if(clothes[i] != 0) continue; // 체육복 빌릴 필요 없음
        if(clothes[i - 1] == 2) { // 앞 사람 체육복 빌림
            clothes[i - 1]--;
            clothes[i]++;
        }
        else if(clothes[i + 1] == 2) { // 뒷 사람 체육복 빌림
            clothes[i + 1]--;
            clothes[i]++;
        }
        else answer--; // 체육복을 빌릴 수 없음
    }
    if(clothes[n] == 0 && clothes[n - 1] != 2) answer--; // 마지막 사람 확인
    return answer;
}