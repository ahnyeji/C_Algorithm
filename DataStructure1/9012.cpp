#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string par;
        cin >> par;
        stack<char> pars;
        int l = par.length();
        int j;
        for(j = 0; j < l; j++){
            if(par[j] == '('){
                pars.push(par[j]);
            }
            else{
                if(!pars.empty() && pars.top() == '('){
                    pars.pop();
                } 
                else{
                    cout << "NO\n";
                    break;
                }
            }
        }
        if(j == l){
            if(pars.empty())
                cout << "YES\n";
            else
            {
                cout << "NO\n";
            }
            
        }
    }
}
