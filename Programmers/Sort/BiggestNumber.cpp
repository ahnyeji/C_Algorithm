#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> nums;
    for(int i : numbers) {
        nums.push_back(to_string(i));
    }
    
    sort(nums.begin(), nums.end(), compare);
    
    if(nums[0] == "0") return "0"; // 0이 여러 번 들어올 수 있음
    
    string answer = "";
    for(string s : nums) {
        answer += s;
    }
    return answer;
}