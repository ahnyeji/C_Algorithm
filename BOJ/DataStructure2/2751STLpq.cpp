/*  BOJ - 2751 : 수 정렬하기 2
    03.February.2021
 */

/*  [STL 활용]
    # priority_queue<자료형, 구현체, 비교 클래스>
        - 내림차순으로 별다른 구현체 제한 없이 단순하게 사용할 경우 'priority_queue<자료형> 변수명' 으로 사용 가능
        - 구현체 : 일반적으로 vector<자료형> 으로 정의 -> vector 활용하여 priority_queue 구현
        - 비교 클래스 : less<자료형> (내림차순, default) / greater<자료형> (오름차순) -> algorithm의 sort에서 사용하는 비교함수와 반대!
        +) 주의 : priority_queue<int, vector<int>, greater<int> > 에서 마지막 '> >' 은 띄어쓰기 권장(시프트 연산자과 구분 위함)
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
        int n;
        cin >> n;
        pq.push(n);
    }

    while(!pq.empty()){
        cout << pq.top() << "\n";
        pq.pop();
    }
}