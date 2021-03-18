#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int len = numbers.size();
    queue<pair<int, int> > q;
    q.push({0, 0});
    while(!q.empty()){
        int now = q.front().first;
        int idx = q.front().second;
        q.pop();
        if(idx == len) {
            if(now == target){
                answer++;
            }
            continue;
        }
        q.push({now - numbers[idx], idx + 1});
        q.push({now + numbers[idx], idx + 1});
    }
    return answer;
}