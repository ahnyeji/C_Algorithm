/*  BOJ - 6603 : 로또
    10.February.2021

    (10.February.2021 Live Problem Solving)
 */

/*  [완전탐색]
    - 조합
*/

#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> s;
vector<int> ans(6);
void comb(int cnt, int idx){
    if(cnt == 6){
        for(int i = 0; i < 6; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    int end = k - (6 - cnt);
    for(int i = idx + 1; i <= end; i++){
        ans[cnt] = s[i];
        comb(cnt + 1, i);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(1){    
        cin >> k;
        if(!k) return 0;
        s.resize(k);
        for(int i = 0; i < k; i++){
            cin >> s[i];
        }
        comb(0, -1);
        cout << "\n";
    }
}