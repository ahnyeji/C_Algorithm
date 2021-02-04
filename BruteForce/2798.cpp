/*  BOJ - 2798 : 블랙잭
    04.February.2021
 */

/*  TC : O(N^3)
    - max(N) : 100 
    - N^3 <= 10^6 < 10^8
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<int> card(N);
    for(int i = 0; i < N; i++){
        cin >> card[i];
    }
    
    int max = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                int sum = card[i] + card[j] + card[k];
                if(sum == M){
                    cout << sum;
                    return 0;
                }
                if(sum < M && sum > max){
                    max = sum;
                }
            }
        }
    }
    cout << max;
}