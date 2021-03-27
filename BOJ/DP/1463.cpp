/*  BOJ - 1463 : 1로 만들기
    15.February.2021
 */

/*  [DP]
    # 기저사례
      - cache[0] : 미사용
      - cache[1] = 0 : 1을 1로 만들기 위해서는 아무 연산도 필요하지 않음 -> 처음에 1이라고 생각해서 오답
      - cache[2] = 1 : 2를 1로 만들기 위해서는 2로 나누거나 1을 빼는 연산 1번이면 가능
      - cache[3] = 1 : 3을 1로 만들기 위해서는 3으로 나누는 연산 1번이면 가능
    # 점화식
      - cache[i] = cache[i / 3] + 1 : 3으로 나누어 떨어지는 경우
      - cache[i] = cache[i / 2] + 1 : 2로 나누어 떨어지는 경우
      - cache[i] = cache[i - 1] + 1 : 3또는 2로 나누어 떨어지지 않는 경우
      - 위의 3가지 방법을 모두 수행한 결과 중 최소값을 가짐
 */

#include <iostream>
#define MIN(x, y) { x > 0 ? (x < y ? x : y) : y}

using namespace std;

int cache[1000001];

int main(){
    cache[1] = 0;
    cache[2] = 1;
    cache[3] = 1;

    int N;
    cin >> N;

    for(int i = 3; i <= N; i++){
        if(i % 3 == 0){
            cache[i] = cache[i / 3] + 1;
        }
        if(i % 2 == 0){
            cache[i] = MIN(cache[i], cache[i / 2] + 1);
        }
        cache[i] = MIN(cache[i], cache[i - 1] + 1);
    }

    cout << cache[N];
}

/* 
Top-down approach 
=> correct on BOJ (21424KB, 28ms)
=> stackoverflow on local computer (when input : 1000000)

#include <iostream>
#define MIN(x, y) { x > 0 ? (x < y ? x : y) : y}

using namespace std;


int cache[1000001];

int toOne(int num){
    if(num == 1) return 0;
    if(num == 2 || num == 3) return 1;
    
    int& ret = cache[num];
    if(ret != 0) return ret;
    
    if(num % 3 == 0){
        ret = toOne(num / 3) + 1;
    }
    if(num % 2 == 0){
        ret = MIN(ret, toOne(num / 2) + 1);
    }
    ret = MIN(ret, toOne(num - 1) + 1);
    return ret;
}

int main(){
    int N;
    cin >> N;
    cout << toOne(N);
}

*/