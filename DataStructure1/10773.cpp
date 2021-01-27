#include <iostream>
#include <stack>
using namespace std;

int main(){
    int K, N;
    cin >> K;
    stack<int> s;
    for(int i = 0; i < K; i++){
        cin >> N;
        if(N == 0){
            s.pop();
        }
        else {
            s.push(N);
        }
    }
    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum;
}