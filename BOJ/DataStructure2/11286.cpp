/*  BOJ - 11286 : 절댓값 힙
    02.February.2021
 */

/*  [STL 활용]
    # priority_queue
        - 자료형을 pair<int, int>로 썼으면 구현체와 비교 연산자의 type도 동일하게 써줘야 함
    # 절댓값 기준 정렬
        - 원래의 값과 절댓값 모두 필요하므로 두 자료를 묶어서 비교
        - 절댓값이 우선 기준, 같은 절댓값 내에서 원래의 값이 기준
 */

#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(x == 0){
            if(pq.empty()){
                cout << "0\n";
            }
            else{
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
        else if(x < 0){
            pq.push(make_pair(-x, x));
        }
        else{
            pq.push(make_pair(x, x));
        }
    }
}