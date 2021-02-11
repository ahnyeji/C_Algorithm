/*  BOJ - 15649 : N과 M(2)
    10.February.2021
 */

/*  [완전탐색]
    - 조합
*/

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> num;

void comb(int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }
    int last = N - (M - cnt - 1);
    for(int i = cnt == 0 ? 1 : num[cnt - 1] + 1; i <= last; i++){
        num[cnt] = i;
        comb(cnt + 1);
    }
}

int main(){
    cin >> N >> M;
    num.resize(M);
    comb(0);
}