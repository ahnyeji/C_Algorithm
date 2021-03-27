/*  BOJ - 1003 : 피보나치 함수
    11.February.2021
 */

/*  [DP]
    - fib[0] = (1, 0) (0 : 1번, 1 : 0번)
    - fib[1] = (0, 1) (0 : 0번, 1 : 1번)
    - fib[n] = fib[n - 1] + fib[n - 2]
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, N;
    cin >> T;
    vector<pair<int,int> > fib(41); // 0 <= N <= 40
    fib[0] = make_pair(1, 0); // 0 : 1, 1 : 0
    fib[1] = make_pair(0, 1); // 0 : 0, 1 : 1
    for(int i = 2 ; i < 41; i++){
        fib[i] = make_pair(fib[i - 1].first + fib[i - 2].first, fib[i - 1].second + fib[i - 2].second);
    }
    while(T--){
        cin >> N;
        cout << fib[N].first << " " << fib[N].second << "\n";
    }
}