/*  [Stack]
    - O(N)
 */

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int len = prices.size();
    answer.assign(len, 0);
    
    stack<int> times;
    times.push(0);
    for(int i = 1; i < len; i++) {
        int before = times.top();
        while(prices[before] > prices[i]) {
            answer[before] = i - before;
            times.pop();
            if(times.empty()) break;
            before = times.top();
        }
        times.push(i);
    }
    len--;
    while(!times.empty()) {
        int t = times.top();
        answer[t] = len - t;
        times.pop();
    }
    return answer;
}

/* Brute Force : O(N^2)
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int plen = prices.size();
    answer.assign(plen, 0);
    for(int i = 0; i < plen; i++) {
        for(int j = i + 1; j < plen; j++) {
            answer[i]++;
            if(prices[i] > prices[j]) break;
        }
    }
    
    return answer;
}
*/