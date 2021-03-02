/*  BOJ - 1920 : 수 찾기
    02.March.2021
 */

/*  [Binary Search]
    # 수열 A를 정렬하여 찾으려는 수의 범위를 좁혀갈 수 있도록 한다
    # 가운데 있는 수와 찾으려는 수를 비교
      - 가운데 수 == 찾으려는 수 : 이미 수를 찾았으므로 해당 수 탐색 종료
      - 가운데 수 > 찾으려는 수 : 수열의 왼쪽 절반에서 다시 탐색 (가운데 수 제외; hi = mid - 1)
      - 가운데 수 < 찾으려는 수 : 수열의 오른쪽 절반에서 다시 탐색 (가운데 수 제외; lo = mid + 1)
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100001];

int main(){
    // Time Over without this part
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A + N);
    cin >> M;
    int num, left, mid, right;
    for(int i = 0; i < M; i++){
        cin >> num;
        left = 0;
        right = N - 1;
        while(left <= right){
            mid = (left + right) / 2;
            if(num == A[mid]){
                cout << "1\n";
                break;
            }
            if(num < A[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(left > right) cout << "0\n";
    }
}