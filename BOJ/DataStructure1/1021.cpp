#include <iostream>
#include <deque>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    deque<int> deq;
    for(int i = N; i > 0; i--){
        deq.push_front(i);
    }
    int ans = 0;
    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        int cnt = 0;
        while(deq.front() != num){
            deq.push_back(deq.front());
            deq.pop_front();
            cnt++;
        }
        if(cnt > deq.size() / 2){
            cnt = deq.size() - cnt;
        }
        deq.pop_front();
        ans += cnt;
    }
    cout << ans;
}
