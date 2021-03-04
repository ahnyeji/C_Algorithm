/*  BOJ - 1931 : 회의실 배정
    04.March.2021
 */

/*  [Greedy]
    # 남은 회의 중에서 종료 시간이 가장 빠른 회의를 택하는 것이 탐욕적
    => 종료 시간이 빠른 순서로 정렬하되, 종료 시간이 같다면 시작 시간이 빠른 순서로 정렬
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comperator(pair<int, int> a, pair<int, int> b){
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int> > meet;
    int s, e;
    for(int i = 0; i < N; i++){
        cin >> s >> e;
        meet.push_back({s, e}); // {start time, end time}
    }
    
    sort(meet.begin(), meet.end(), comperator);

    int cnt = 1;
    e = meet[0].second;
    for(int i = 1; i < N; i++){
        if(e <= meet[i].first){ // last meeting end time <= current meeting start time : possible
            cnt++;
            e = meet[i].second;
        }
    }
    cout << cnt;
}