/*  BOJ - 2108 : 통계학
    03.February.2021
 */

/*  [STL 활용]
    # algorithm STL -> sort()
        - sort(start, end, 비교 함수)
            예 1) sort(arr, arr + n, greater<int>());
            예 2) sort(v.begin(), v.end());
        - 비교 함수
            pair의 first와 second 정렬 방식이 달라 compare 함수 작성
    # cmath STL -> round()
        - int 간 계산 시 양수는 소수점 버림(4.7 -> 4), 음수는 소수점 올림(-4.7 -> -4)
        - 반올림 연산 시 cmath 라이브러리의 round() 필요
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// pair : (count, number) -> count : descending, number : ascending
bool compare(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}

int main(){
    int N;
    cin >> N;

    vector<int> v;
    int sum = 0;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        v.push_back(n);
        sum += n;
    }

    // 1. average
    cout << round((double)sum / N) << "\n";

    // 2. median : middle data sorted ascending
    sort(v.begin(), v.end());
    if(N % 2 == 0){ // the number of data : even -> avg of 2 middle numbers
        cout << (v[N / 2 - 1] + v[N / 2]) / 2 << "\n";
    } 
    else{
        cout << v[N / 2] << "\n";
    }

    // 3. mode
    vector<pair<int, int> > cnts;
    int cnt = 0;
    for(int i = 1; i < N; i++){
        cnt++;
        if(v[i] != v[i - 1]){
            cnts.push_back(make_pair(cnt, v[i - 1]));
            cnt = 0;
        }
    }
    cnts.push_back(make_pair(++cnt, v[N - 1]));
    sort(cnts.begin(), cnts.end(), compare);
    
    if(cnts.size() > 1 && cnts[0].first == cnts[1].first){
        cout << cnts[1].second << "\n";
    }
    else{
        cout << cnts[0].second << "\n";
    }
    
    // 4. range
    cout << v[N - 1] - v[0];
}