/*  BOJ - 1655 : 가운데를 말해요
    04.February.2021
 */

/*  [Priority Queue]
    (시간 제한 0.1초 -> 정렬해서 중앙값 뽑으려면 시간초과)
    - 작은 수(Smaller; priority_queue / max) & 중앙 값(MID; int) & 큰 수(Bigger; priority_queue / min)
        0. 자료구조
            - 작은 수 : 작은 수 중 가장 큰 수를 뽑아야 하므로 Max Heap
            - 큰 수 : 큰 수 중 가장 작은 수를 뽑아야 하므로 Min Heap
        1. 수의 개수
            - 중앙 값은 무조건 한 개
            - 홀수 개의 수가 저장되어 있을 때
                : cnt(Smaller) == cnt(Bigger)
            - 짝수 개의 수가 저장되어 있을 때
                : cnt(Smaller) == cnt(Bigger) - 1
                 (중앙 값은 더 작은 수이기 때문)
            - 저장되어 있는 수의 전체 개수 == 인덱스(i)
        2. 중앙 값(MID) vs 새로운 수(N)
            - MID > N -> Smaller.push(N) & MID < N -> Bigger.push(N)
            - MID == N -> 저장되어 있는 수의 개수에 따라 다름
            - 새로운 수 넣기 전 홀수 개의 수가 저장되어 있을 때
                a. 현재 중앙 값보다 작은 수 넣으면 (MID > N)
                    : cnt(Smaller) > cnt(Bigger)  !!조정 필요!!
                      => (MID -> Bigger) && (Smaller -> MID) 이동
                b. 현재 중앙 값과 같거나 큰 수 넣으면 (MID <= N)
                    : cnt(Smaller) == cnt(Bigger) - 1 (짝수 개 저장 개수!)
            - 새로운 수 넣기 전 짝수 개의 수가 저장되어 있을 때
                a. 현재 중앙 값보다 큰 수 넣으면 (MID < N)
                    : NEW -> 큰 수
                      => cnt(Smaller) < cnt(Bigger) - 1  !!조정 필요!!
                      => (MID -> Smaller) && (Bigger -> MID) 이동
                b. 현재 중앙 값과 같거나 작은 수 넣으면 (MID >= N)
                    : cnt(Smaller) == cnt(Bigger) (홀수 개 저장 개수!)
 */

#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<> > bigger;
    
    int mid;
    cin >> mid;
    cout << mid << "\n";
    
    for(int i = 1; i < N; i++){
        int n;
        cin >> n;

        if(i % 2 == 0){
            if(mid < n){
                bigger.push(n);
                smaller.push(mid);
                mid = bigger.top();
                bigger.pop();
            }
            else smaller.push(n);
        }
        else{
            if(mid > n){
                smaller.push(n);
                bigger.push(mid);
                mid = smaller.top();
                smaller.pop();
            }
            else bigger.push(n);
        }
        cout << mid << "\n";
    }
    
}