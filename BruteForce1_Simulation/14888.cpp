/*  BOJ - 14888 : 연산자 끼워넣기
    05.February.2021
 */

/*  [완전 탐색 - DFS]
    # 모든 연산자 조합, 순열 생각하기
      - 같은 연산자는 조합, 다른 연산자는 순열
      - 연산자 우선순위 없이 앞에서부터 연산 진행
        => 마지막 연산까지 끝내야 최대 / 최소 알 수 있음
        => 깊이 우선 탐색 DFS
    # DFS
      - +, -, *, / : 연산자 4개 -> 깊이 하나씩 들어갈 때마다 4가지 경우 탐색
      - 더 이상 연산할 것 없으면 return

    TC : O(4^n)
    - max(N) : 10
    - 4^n <= 2^20 < 8^7 < 10^7 < 10^8
 */

#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> a;

// result : (max, min) result of calculated before idx
// idx : index of 2nd operand
// plus, minus, mult, divide : 
pair<int, int> operating(pair<int, int> result, int idx, int plus, int minus, int mult, int div){
    int rMax = result.first;
    int rMin = result.second;
    
    if(idx == N) return result;
    int max = -1000000000;
    int min = 1000000000;
    pair<int, int> cal;

    if(plus > 0){
        cal = operating(make_pair(rMax + a[idx], rMin + a[idx]), idx + 1, plus - 1, minus, mult, div);
        max = max < cal.first ? cal.first : max;
        min = min > cal.second ? cal.second : min;
    }
    if(minus > 0){
        cal = operating(make_pair(rMax - a[idx], rMin - a[idx]), idx + 1, plus, minus - 1, mult, div);
        max = max < cal.first ? cal.first : max;
        min = min > cal.second ? cal.second : min;
    }
    if(mult > 0){
        cal = operating(make_pair(rMax * a[idx], rMin * a[idx]), idx + 1, plus, minus, mult - 1, div);
        max = max < cal.first ? cal.first : max;
        min = min > cal.second ? cal.second : min;
    }
    if(div > 0){
        cal = operating(make_pair(rMax / a[idx], rMin / a[idx]), idx + 1, plus, minus, mult, div - 1);
        max = max < cal.first ? cal.first : max;
        min = min > cal.second ? cal.second : min;
    }
    cal.first = max;
    cal.second = min;
    return cal;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        a.push_back(n);
    }

    vector<int> op(4);
    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }
    pair<int, int> r = operating(make_pair(a[0], a[0]), 1, op[0], op[1], op[2], op[3]);
    cout << r.first << "\n" << r.second;
}