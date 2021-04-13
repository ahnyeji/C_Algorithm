#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> totcnt; // 장르별 재생 횟수
    unordered_map<string, priority_queue<pair<int, int>>> gplays; // 장르별 곡과 재생 횟수 목록
    int len = genres.size();
    for(int i = 0; i < len; i++) {
        totcnt[genres[i]] += plays[i];
        gplays[genres[i]].push(make_pair(plays[i], -i)); // 재생 횟수는 큰 순, 고유 번호는 작은 순
    }
    
    priority_queue<pair<int, string>> totplays; // 총 재생횟수 많은 순으로 장르 정렬하기 위함
    for(auto tot : totcnt) {
        totplays.push(make_pair(tot.second, tot.first));
    }
    
    while(!totplays.empty()) {
        string g = totplays.top().second;
        totplays.pop();
        answer.push_back(-gplays[g].top().second);
        gplays[g].pop();
        if(!gplays[g].empty()) answer.push_back(-gplays[g].top().second);
    }
    return answer;
}