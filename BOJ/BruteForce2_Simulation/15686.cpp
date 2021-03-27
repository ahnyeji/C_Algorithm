/*  BOJ - 15686 : 치킨 배달
    20.February.2021
    (20.February.2021 Live Problem Solving)
 */

/*  [BruteForce]
    # 조합 : 치킨집 고르기
    [Simulation]
    # 치킨 거리 구하기
 */

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> homeR;
vector<int> homeC;
vector<int> chickenR;
vector<int> chickenC;
int cntChicken;
int ans = 250000;

void comb(int cnt, int idx, vector<int> selectedChicken){
    if(cnt == 0){ // calculate chicken distance
        int len = homeR.size();
        int totalVal = 0;
        for(int i = 0; i < len; i++){ // each home
            int minVal = N * 2;
            for(int j = 0; j < M; j++){ // find minimum distance from current home
                int dx = homeC[i] - chickenC[selectedChicken[j]];
                dx = dx > 0 ? dx : -dx; // abs
                int dy = homeR[i] - chickenR[selectedChicken[j]];
                dy = dy > 0 ? dy : -dy; // abs
                minVal = minVal > dx + dy ? dx + dy : minVal;
            }
            totalVal += minVal;
        }
        ans = ans > totalVal ? totalVal : ans;
        return;
    }
    // combination
    int lastIdx = cntChicken - cnt + 1;
    for(int i = idx + 1; i < lastIdx; i++){
        selectedChicken.push_back(i);
        comb(cnt - 1, i, selectedChicken);
        selectedChicken.pop_back();
    }
}

int main(){
    cin >> N >> M;
    int n;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> n;
            if(n == 1){ // save home
                homeR.push_back(i);
                homeC.push_back(j);
            }
            if(n == 2){ // save chicken restaurant
                chickenR.push_back(i);
                chickenC.push_back(j);
            }
        }
    }
    cntChicken = chickenR.size();
    vector<int> init;
    comb(M, -1, init);

    cout << ans;
}