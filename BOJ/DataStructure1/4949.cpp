#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string s;
    while(1){
        getline(cin, s);
        if(s[0] == '.') break;
        stack<char> pars;
        int check = 1;
        int len = s.length() - 1;
        for(int i = 0; i < len; i++){
            if(s[i] == '(' || s[i] == '['){
                pars.push(s[i]);
            }
            else if(s[i] == ')'){
                if(!pars.empty() && pars.top() == '('){
                    pars.pop();
                }
                else{
                    cout << "no\n";
                    check--;
                    break;
                }
            }
            else if(s[i] == ']'){
                if(!pars.empty() && pars.top() == '['){
                    pars.pop();
                }
                else{
                    cout << "no\n";
                    check--;
                    break;
                }
            }
        }
        if(check){
            if(pars.empty()){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
        }
    }
}