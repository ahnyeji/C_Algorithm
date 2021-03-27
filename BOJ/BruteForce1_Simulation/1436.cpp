/*  BOJ - 1436 : 영화감독 숌
    10.February.2021

    (06.February.2021 Live Problem Solving)
 */

#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    int six = 666;
    while(1){
        string s = to_string(six);
        if(s.find("666")!=string::npos){
            n--;
        }
        if(n==0){
            cout << six;
            break;
        }
        six++;
    }
}
