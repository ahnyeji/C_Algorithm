/*  BOJ - 10448 : 유레카 이론
    05.February.2021
 */

/*  TC : O(N^3)
    - N : sqrt(K * 2) (삼각수 N이 T보다 클 필요 없음 / 삼각수 : N(N+1)/2)
    - max(N) : 45 (근사값; K <= 1000)
    - N^3 < 10^5 < 10^8

    !! Test Case 개수 주어지지 않음 (https://www.acmicpc.net/board/view/23033#comment-49324)
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T, K;
    cin >> T;
    
    vector<int> tri; // save triangular numbers
    int idx = 0; // last index of triangular number in tri
    int tn = 0; // triangular number of idx
    
    while(T--){
        cin >> K;
        // make triangular number (once make, next Test case can use existing tri)
        while(tn < K){
            tn = ++idx * (idx + 1) / 2;
            tri.push_back(tn);
        }
        int check = 0;
        for(int i = 0; i < idx; i++){
            for(int j = i; j < idx; j++){
                for(int k = j; k < idx; k++){
                    if(K == tri[i] + tri[j] + tri[k]){
                        check = 1;
                        break;
                    }
                }
                if(check){
                    break;
                }
            }
            if(check){
                break;
            }
        }
        cout << check << "\n";
    }
}