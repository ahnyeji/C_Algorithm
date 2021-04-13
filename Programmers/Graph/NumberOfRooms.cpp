#include <string>
#include <vector>
#include <map>
using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int solution(vector<int> arrows) {
    int answer = 0;
    
    map<pair<int, int>, bool> nodes;
    map<pair<pair<int, int>, pair<int, int>>, bool> edges;
    
    int x = 0, y = 0;
    nodes[{x, y}] = 1;
    for(int d : arrows) {
        for(int i = 0; i < 2; i++) { // 한 번 이동을 반으로 쪼개어 두 번 이동한다고 생각 (교차점 고려를 위함)
            int xx = x + dx[d];
            int yy = y + dy[d];
            
            if(nodes[{xx, yy}] == 1 && edges[{{x, y}, {xx, yy}}] == 0) answer++;
            
            nodes[{xx, yy}] = 1;
            edges[{{x, y}, {xx, yy}}] = 1;
            edges[{{xx, yy}, {x, y}}] = 1;
            x = xx;
            y = yy;
        }
    }
    
    return answer;
}