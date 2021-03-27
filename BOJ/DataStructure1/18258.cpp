#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    // 시간초과 해결을 위한 부분 (사용 시 cin, cout만 사용)
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    queue<int> q;
    for(int i = 0; i < N; i++){
        string order;
        cin >> order;
        if(order == "push"){
            int num;
            cin >> num;
            q.push(num);
        }
        else if(order == "pop"){
            if(q.empty()){
                cout << "-1\n";
            }
            else{
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(order == "empty"){
            cout << (q.empty() ? 1 : 0) << "\n";
        }
        else if(order == "front"){
            cout << (q.empty() ? -1 : q.front()) << "\n";
        }
        else if(order == "back"){
            cout << (q.empty() ? -1 : q.back()) << "\n";
        }
        else{
            cout << q.size() << "\n";
        }
    }
}