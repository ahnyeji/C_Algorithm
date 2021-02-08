#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    if(N == 1){
        cout << 0;
        return 0;
    }
    
    int i = 1;
    for(; i < N; i++){
        int n = i;
        int m = n;
        while(n > 0){
            m += (n % 10);
            n /= 10;
        }
        if(m == N){
            cout << i;
            return 0;
        }
    }
    if(i == N){
        cout << 0;
        
    }
}