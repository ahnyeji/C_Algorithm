#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    int len = times.size();
    sort(times.begin(), times.end());
    long long lo = times[0];
    long long hi = (long long)times[len - 1] * n; // times는 int형임에 주의!
    
    while(lo < hi) {
        long long mid = (lo + hi) / 2;
        long long cnt = 0;
        for(int i = 0; i < len; i++) {
            cnt += mid / times[i];
        }
        if(cnt < n) lo = mid + 1;
        else hi = mid;
    }
    
    return hi;
}