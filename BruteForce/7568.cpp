/*  BOJ - 7568 : 덩치
    04.February.2021
 */

/*  TC : O(N^2)
    - max(N) : 50 
    - N^2 <= 2500 < 10^8
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, x, y;
    vector<pair<int, int> > size;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        size.push_back(make_pair(x, y));
    }

    for(int i = 0; i < N; i++){
        int rank = 1;
        for(int j = 0; j < N; j++){
            if(size[i].first < size[j].first && size[i].second < size[j].second){
                rank++;
            }
        }
        cout << rank << " ";
    }
}