/*  BOJ - 12015 : 가장 긴 증가하는 부분 수열 2
    09.March.2021
 */

/*  [BinarySearch - LowerBound]
    # lower bound 직접 구현
 */

#include <iostream>

using namespace std;

int N;
int A[1000001];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    cin >> A[0];
    
    int n;

    int lo, hi, mid, len = 1;
    while(--N){
        cin >> n;
        if(A[len - 1] < n){
            A[len++] = n;
            continue;
        }
        lo = 0;
        hi = len - 1;
        while(lo <= hi){ // find lowerbound
            mid = (lo + hi) / 2;
            if(A[mid] < n){
                lo = mid + 1;
            }    
            else{
                hi = mid - 1;
            }
        }
        A[lo] = n;
    }
    cout << len << "\n";
}