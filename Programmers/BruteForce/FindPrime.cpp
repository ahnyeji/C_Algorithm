#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string number;
int len;
vector<bool> visit;
unordered_set<int> num; // 만들어진 소수 저장하는 변수

bool isPrime(int n) { // 소수 확인 함수
    if(n == 0 || n == 1) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void makePrime(int cnt, int now) {
    if(cnt == len) return; // 더 이상 사용 가능한 수 없음
    for(int i = 0; i < len; i++) {
        if(!visit[i]) { // 해당 수 사용 가능
            visit[i] = true;
            int n = now * 10 + (number[i] - '0');
            if(isPrime(n)) num.insert(n);
            makePrime(cnt + 1, n); // 현재 만들어진 수가 소수가 아니어도 뒤에 다른 수를 붙여 소수될 수 있음
            visit[i] = false;
        }
    }
}

int solution(string numbers) {
    number = numbers;
    len = numbers.length();
    visit.assign(len, false);
    makePrime(0, 0);
    int answer = 0;
    answer = num.size(); // 소수만 들어가 있고 중복을 허용하지 않으므로 개수만 세면 됨
    return answer;
}