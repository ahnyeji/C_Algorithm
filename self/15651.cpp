/*  BOJ - 15649 : N과 M(2)
    10.February.2021
 */

/*  [완전탐색]
    - 중복순열
*/

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> num;

void product(int cnt){
    if(!cnt){
        for(int i = 0; i < M; i++){
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        num.push_back(i);
        product(cnt - 1);
        num.pop_back();
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    product(M);
}

/* faster version
int N, M;
char num[15];

void product(int cnt){
    if(cnt == M){
        cout << num << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        num[cnt * 2] = i + '0';
        num[cnt * 2 + 1] = ' ';
        product(cnt + 1);
        num[cnt * 2] = '0';
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    product(0);
}
*/