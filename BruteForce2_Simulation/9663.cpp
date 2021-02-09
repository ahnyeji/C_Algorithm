/*  BOJ - 9663 : N-Queen
    09.February.2021
 */

/*  [BackTracking]
    1. 0번째 행부터 n개 행에 순서대로 queen 배치
    2. 이전에 배치된 queen과 같은 열, 같은 대각선에 존재할 수 없음 (이미 행은 구분해 둔 상태이므로 중복x)
        -> 현재 queen을 놓아야하는 행을 row라 할 때
            1) 0 ~ n-1 열과 0 ~ row-1 행에 놓여있는 queen의 열을 비교
                a. 같으면 유망하지 않음 -> 가지치기
                b. 다르면 대각선 검사 (이전 행에 놓여있는 queen의 행, 열과 현재 확인 중인 행, 열의 차 이용)
                    a) 기울기가 1 (차가 같음) 또는 -1 (차가 -1배와 같음)이면 유망하지 않음 -> 가지치기
                    b) 기울기가 1 또는 -1이 아니면 유망함 -> 다음 행 비교
*/

#include <iostream>
#include <vector>

using namespace std;

int N, ans = 0;
vector<int> queen;
void DFS(int row){
    if(row == N){ // all queens on board
        ans++;
        return;
    }
    for(int i = 0; i < N; i++){ // column to put new queen
        bool check = true; // to check whether can put queen on column i
        for(int j = 0; j < row; j++){ // queens already on chess board
            if(i == queen[j]){ // already on same column -> pruning
                check = false;
                break;
            } 
            int y = row - j; // dy
            int x = i - queen[j]; // dx
            if(x == y || x == -y){ // already on cross -> pruning
                check = false;
                break;
            }
        }
        
        if(check){ // can put queen on this column
            queen[row] = i; // put queen
            DFS(row + 1); // next queen
            queen[row] = -1; // find other column
        }
    }
}

int main(){
    cin >> N;

    queen.assign(N, -1);
    DFS(0);
    cout << ans;
}