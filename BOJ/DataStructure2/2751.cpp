/*  BOJ - 2751 : 수 정렬하기 2
    03.February.2021
 */

/*  [STL 활용]
    # algorithm STL -> sort()
        - sort(start, end, 비교 함수)
            예 1) sort(arr, arr + n, greater<int>());
            예 2) sort(v.begin(), v.end());
        - 비교 함수 : less<자료형>() (오름차순, default) / greater<자료형>() (내림차순)
            +) 주의 : priority_queue는 비교 클래스 사용하여 비교 함수와 반대
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> v;
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++){
        cout << v[i] << "\n";
    }
}