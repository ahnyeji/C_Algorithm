#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    int len = rocks.size();
    int answer = 0;
    
    // 바위 간 간격 최소값으로 이분탐색 수행
    int lo = 1;
    int hi = distance;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        int remove = 0; // 제거한 바위 수
        int prev = 0; // 이전 바위 지점
        
        for(int i = 0; i < len; i++) { // 모든 바위 확인
            if(rocks[i] - prev < mid) { // 최소값보다 바위 간 간격이 작음 -> 바위 제거
                remove++;
                if(remove > n) break;
            }
            else prev = rocks[i]; // 이전 바위 지점 갱신
        }
        if(distance - prev < mid) remove++; // 마지막 바위와 도착지 간 간격
        
        if(remove > n) hi = mid - 1; // 설정한 바위 간격이 넓어서 더 많은 바위를 제거 -> 줄여야 함
        else lo = mid + 1;
    }
    
    return hi;
}