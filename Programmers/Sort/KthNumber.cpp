#include <string>
#include <vector>
#include <algorithm> // for sorting

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int len = commands.size();
    for(int i = 0; i < len; i++) {
        int from = commands[i][0] - 1; // 입력 인덱스는 1부터 시작하지만 실제 인덱스는 0부터 시작하므로 1 감소
        int to = commands[i][1]; // 입력 인덱스는 1부터 시작하여 1 감소 해야하지만 마지막 인덱스까지 포함하기 위해 감소x
        int idx = commands[i][2] - 1; // 입력 인덱스는 1부터 시작하지만 실제 인덱스는 0부터 시작하므로 1 감소
        
        vector<int> subarray; // from ~ to 부분 배열
        subarray.assign(array.begin() + from, array.begin() + to); // assign(begin, end) -> begin은 포함, end는 제외
        sort(subarray.begin(), subarray.end()); // 정렬
        answer.push_back(subarray[idx]);
    }
    return answer;
}