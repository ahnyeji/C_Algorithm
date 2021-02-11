/*  BOJ - 15649 : N과 M(1)
    10.February.2021
 */

/*  [완전탐색]
    - 순열
*/

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<bool> check;
vector<int> nums;

void perm(int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << nums[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        if(!check[i]){
            check[i] = 1;
            nums[cnt] = i;
            perm(cnt + 1);
            check[i] = 0;
        }
    }
}

int main(){
    cin >> N >> M;
    check.resize(N + 1);
    nums.resize(N + 1);
    perm(0);
}