#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        string fun, seq;
        int n;
        cin >> fun >> n >> seq;
        if(n == 0){
            int i = 0;
            int len = fun.length();
            for(; i < len; i++){
                if(fun[i] == 'D'){
                    cout << "error\n";
                    break;
                }
            }
            if(i == len){
                cout << "[]\n";
            }
            continue;
        }
        deque<int> num;
        int len = seq.length();
        int parsing = 0;
        for(int i = 0; i < len; i++){
            if(seq[i] == ',' || seq[i] == ']'){
                num.push_back(parsing);
                parsing = 0;
            }
            else if(seq[i] != '['){
                parsing = parsing * 10 + (seq[i] - '0');
            }
        }
        int dir = 1;
        len = fun.length();
        int i = 0;
        for(; i < len; i++){
            if(fun[i] == 'R'){
                dir *= -1;
            }
            else{
                if(num.empty()){
                    cout << "error\n";
                    break;
                }
                else{
                    dir == 1 ? num.pop_front() : num.pop_back();
                }
            }
        }
        if(i == len){
            cout << "[" ;
            while(num.size() > 1){
                if(dir == 1){
                    cout << num.front() << ",";
                    num.pop_front();
                }
                else{
                    cout << num.back() << ",";
                    num.pop_back();
                }
            }
            if(num.size() == 1){
                cout << num.front();
            }
            cout << "]\n";
        }
    }
}