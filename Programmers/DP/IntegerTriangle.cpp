#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int len = triangle.size() - 1;
    for(int i = len; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            triangle[i - 1][j] += triangle[i][j] < triangle[i][j + 1] ? triangle[i][j + 1] : triangle[i][j];
        }
    }
    
    return triangle[0][0];
}

/*  원본 데이터 유지
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int len = triangle.size();
    vector<vector<int>> dp;
    dp.push_back(vector<int>(1, triangle[0][0]));
    for(int i = 1; i < len; i++) {
        vector<int> row;
        int j = 0;
        for(int j = 0; j <= i; j++) {
            int sum = triangle[i][j];
            if(j == 0) sum += dp[i - 1][j];
            else if(j == i) sum += dp[i - 1][j - 1];
            else sum += dp[i - 1][j - 1] > dp[i - 1][j] ? dp[i - 1][j - 1] : dp[i - 1][j];
            row.push_back(sum);
            answer = answer < sum ? sum : answer;
        }
        dp.push_back(row);
    }
    
    return answer;
}
*/