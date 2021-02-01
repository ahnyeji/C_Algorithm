/*  BOJ - 1927 : 최소 힙
    01.February.2021
 */

/*  [STL 활용]
    # priority_queue<자료형, 구현체, 비교 연산자>
    구현체 : 일반적으로 vector<자료형> 으로 정의 -> vector 활용하여 priority_queue 구현
    비교 연산자 : less<자료형> (내림차순, default) / greater<자료형> (오름차순)
*/
#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(x){
            pq.push(x);
        }
        else{
            if(pq.empty()){
                cout << "0\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}