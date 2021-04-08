#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int len = citations.size();
    
    int answer = 0;
    while(answer < len) {
        if(citations[answer] <= answer) break;
        answer++;
    }
    return answer;
}