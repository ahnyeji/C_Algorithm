#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int, vector<int>, greater<int> > minh;
    priority_queue<int, vector<int>, less<int> > maxh;
    
    int cnt = 0;
    for(string op : operations) {
        if(op[0] == 'I') {
            int num = stoi(op.substr(2));
            minh.push(num);
            maxh.push(num);
            cnt++;
        }
        else {
            if(cnt == 0) continue;
            if(op[2] == '-') minh.pop();
            else maxh.pop();
            cnt--;
        }
        if(cnt == 0) {
            while(!minh.empty()) minh.pop();
            while(!maxh.empty()) maxh.pop();
        }
    }
    vector<int> answer;
    answer.push_back(cnt == 0 ? 0 : maxh.top());
    answer.push_back(cnt == 0 ? 0 : minh.top());
    return answer;
}