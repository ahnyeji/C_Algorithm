#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    // 이 부분 추가하면 4ms, 안하면 352ms
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    deque<int> deq;
    for(int i = 0; i < N; i++){
        string order;
        cin >> order;
        if(order == "push_front"){
            int num;
            cin >> num;
            deq.push_front(num);
        }
        else if(order == "push_back"){
            int num;
            cin >> num;
            deq.push_back(num);
        }
        else if(order == "pop_front"){
            if(deq.empty()){
                cout << "-1\n";
            }
            else{
                cout << deq.front() << "\n";
                deq.pop_front();
            }
        }
        else if(order == "pop_back"){
            if(deq.empty()){
                cout << "-1\n";
            }
            else{
                cout << deq.back() << "\n";
                deq.pop_back();
            }
        }
        else if(order == "size"){
            cout << deq.size() << "\n";
        }
        else if(order == "empty"){
            cout << (deq.empty() ? 1 : 0) << "\n";
        }
        else if(order == "front"){
            cout << (deq.empty() ? -1 : deq.front()) << "\n";
        }
        else{
            cout << (deq.empty() ? -1 : deq.back()) << "\n";
        }
    }
}