#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> numbers;
    for(string pnum : phone_book) {
        string subp = "";
        int len = pnum.size();
        for(int i = 0; i < len; i++) {
            subp += pnum[i];
            numbers[subp]++;
        }
    }
    
    for(string pnum : phone_book) {
        if(numbers[pnum] > 1) return false;
    }
    
    return true;
}