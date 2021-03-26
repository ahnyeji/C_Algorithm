#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    for(int i = 0; i < bridge_length; i++) { // 다리 위를 다리 길이만큼 0으로 초기화
        bridge.push(0);
    }
    int len = truck_weights.size();
    int w = 0; // 다리 위에 있는 트럭 무게 총합
    for(int i = 0; i < len; i++) {
        while(w - bridge.front() + truck_weights[i] > weight) { // 다리 위에 새 트럭 올릴 수 있을 때까지 앞 트럭 빼기
            w -= bridge.front();
            bridge.pop();
            bridge.push(0);
            answer++;
        }
        // 새 트럭 올리기
        w -= bridge.front();
        bridge.pop();
        w += truck_weights[i];
        bridge.push(truck_weights[i]);
        answer++;
    }
    answer += bridge_length; // 마지막으로 다리 위에 올라간 트럭이 빠져나가는 시간
    return answer;
}