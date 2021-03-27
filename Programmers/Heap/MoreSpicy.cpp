#include <string>
#include <vector>
#include <queue> // priority_queue 사용을 위함 (priority_queue는 클수록 우선순위 높음)

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    int cnt0 = 0; // 0이 여러 번 등장하면 한 번만 추가 (0 2개 섞으면 0 1개 됨 -> 최종적으로 0 1개 됨)
    int len = scoville.size();
    for(int i = 0; i < len; i++) {
        if(scoville[i] != 0) pq.push(-scoville[i]); // 스코빌지수 작은 순서로 필요하므로 음수화 하여 가장 큰 수 양수화하여 사용
        else cnt0++;
    }
    if(cnt0 > 0) pq.push(0);
    while(pq.size() > 1 && -pq.top() < K) { // 음수로 들어가 있으므로 양수화하여 비교
        int sc = pq.top(); // 연산 시에는 양수화 불필요 (음수화하여 값 넣을 것이기 때문)
        pq.pop();
        sc += pq.top() * 2;
        pq.pop();
        pq.push(sc);
        answer++;
    }
    if(-pq.top() < K) answer = -1;
    return answer;
}