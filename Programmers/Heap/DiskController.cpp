#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue<pair<int, int> > schedule;
    int len = jobs.size();
    int idx = 0, t = 0;
    while(idx < len || !schedule.empty()) {
        if(idx < len && jobs[idx][0] <= t) {
            schedule.push(make_pair(-jobs[idx][1], jobs[idx][0])); // priority_queue : max heap -> 짧은 시간을 우선순위로 두기 위해 음수화하여 저장
            idx++;
            continue;
        }
        if(!schedule.empty()) {
            t -= schedule.top().first; // 음수 데이터이므로 빼기
            answer += t - schedule.top().second;
            schedule.pop();
        }
        else {
            t = jobs[idx][0];
        }
    }
    return answer / len;
}