#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string order;
        cin >> order;
        int n;
        if(order == "push"){
            cin >> n;
            s.push(n);
        } 
        else if(order == "pop"){
            if(s.empty()){
                cout << -1 << "\n";
            } 
            else{
                cout << s.top() << "\n";
                s.pop();
            }
        } 
        else if(order == "size"){
            cout << s.size() << "\n";
        } 
        else if(order == "empty"){
            cout << (s.empty() ? 1 : 0) << "\n";
        } 
        else if(order == "top"){
            if(s.empty()){
                cout << -1 << "\n";
            }
            else {
                cout << s.top() << "\n";
            }
        }
    }
}