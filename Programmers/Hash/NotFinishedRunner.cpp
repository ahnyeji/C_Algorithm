#include <string>
#include <vector>
#include <unordered_map> // Hash Table을 사용하는 map (STL; hash_map은 STL이 아님)

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> comp; // key : string (완주 선수 이름), value : int (이름 등장 횟수)
    for(string c : completion) { // 완주자 명단 작성 (이 명단에 없는 participant가 답)
        comp[c]++; // 완주 선수 이름이 등장할 때마다 횟수를 하나씩 증가 (없는 선수라면 0으로 생성해서 1 증가)
    }
    for(string p : participant) { // 참가자와 완주자 명단 비교
        if(comp.find(p) == comp.end() || comp[p] == 0) { // 이름이 없거나 완주자 명단에 있는 동명이인이 전부 지나간 경우
            answer = p;
            break;
        }
        comp[p]--;
    }
    return answer;
}