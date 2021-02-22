/*  BOJ - 11054 : 가장 긴 바이토닉 부분 수열
    20.February.2021
    (20.February.2021 Live Problem Solving)
 */

/*  [DP]
    # BOJ 11053 가장 긴 증가하는 부분 수열 -> 응용하여 풀 수 있음
    https://github.com/ahnyeji/C_Algorithm/blob/main/DP/11053.cpp
*/

#include <iostream>

using namespace std;

int N;

int A[1001]; // original sequence
int incfront[1001]; // increasing sequence length
int incback[1001]; // decreasing sequence length

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    // increasing (increasing front -> back) : longest sequence include current element when current is biggest num
    for(int i = 0; i < N; i++){
        for(int j = i - 1; j >= 0; j--){
            if(A[j] < A[i]){
                incfront[i] = incfront[i] < incfront[j] ? incfront[j] : incfront[i];
            }
        }
        incfront[i]++;
    }

    // decreasing (increasing back -> front) : longest sequence include current element when current is biggest num
    for(int i = N - 1; i >= 0; i--){
        for(int j = i + 1; j < N; j++){
            if(A[j] < A[i]){
                incback[i] = incback[i] < incback[j] ? incback[j] : incback[i];
            }
        }
        incback[i]++;
    }

    // get longest bitonic sequence : longest sequence include current element when current is biggest num
    int max = 2;
    for(int i = 0; i < N; i++){
        max = max < incfront[i] + incback[i] ? incfront[i] + incback[i] : max;
    }
    cout << max - 1; // maximum element counted twice (incfront & incback)
}