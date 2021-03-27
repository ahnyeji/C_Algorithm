/*  BOJ - 1107 : 리모컨
    12.February.2021

    (10.February.2021 Live Problem Solving)
 */

/*  [완전탐색]
    - 놓친 부분
      1. 이동하기 위한 수보다 작은 자리수의 숫자가 답이 될 수도 있다
        (N : 1001, M : 2, button : 0 1 인 경우 999일 때가 답)
      2. 작은 자리수 숫자를 찾기 위해 findNum 내 for loop 시작을 0부터 하더라도 0번 버튼이 고장나있으면 반영 불가
        -> 한 자리 작은 수 탐색을 위해 findNum(1, 0) 추가
      3. 만약 0번 버튼이 고장났다면 탐색한 수가 0일 경우는 결과 반영하면 안됨
*/

#include <iostream>
#include <vector>
using namespace std;

vector<bool> buttons(10);
string n;
int N, M, len, mini, now = 100;

void findNum(int cnt, int num){
    if(cnt == len){
        if(!num && buttons[0]) return; // num is 0 but 0 button broken
        mini = min(mini, abs(N - num) + (int)to_string(num).length());
        return;
    }
    if(!cnt && buttons[0]){ // to find 1 less digit numbers
        findNum(1, 0);
    }
    for(int i = 0; i < 10; i++){
        if(!buttons[i]){
            findNum(cnt + 1, num * 10 + i);
        }
    }
}

int main(){
    cin >> n;
    cin >> M;
    for(int i = 0; i < M; i++){
        int b;
        cin >> b;
        buttons[b] = 1;
    }

    N = stoi(n);
    if(N >97 && N < 104){ // always + or - button works faster (or same)
        cout << abs(N - now);
        return 0;
    }
    
    len = n.length();
    bool same = 1;
    for(int i = 0; i < len; i++){ // whether can move to N without + or - button
        if(buttons[n[i] - '0']){
            same = 0;
            break;
        }
    }
    if(same){ // can move without + or - button
        cout << len;
        return 0;
    }

    mini = abs(N - now);
    findNum(0, 0);
    // check smallest number that has 1 more digit (bigger than N)
    // e.g.) 9999 -> 10000 or 11111
    // if 0 & 1 all broken, don't need to check (smaller number than N push less buttons)
    if(!buttons[1]){ 
        int zerone = 1;
        if(!buttons[0]) zerone = 0;
        int num = 1;
        for(int i = 0; i < len; i++){
            num = num * 10 + zerone;
        }
        mini = min(mini, num - N + len + 1);
    }
    cout << mini;

}