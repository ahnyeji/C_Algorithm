/*  BOJ - 1427 : 소트인사이드
    02.February.2021
 */

/*  [STL 활용]
    # priority_queue
    # 입력
        - 숫자가 아닌 하나의 문자열로 입력 처리 (길이 미리 알 수 없으므로 %1d 사용 불가)
        - 문자열 한 번 받아오므로 cin.tie(NULL) 필요 없음
        - 문자열의 각 문자 활용 위해 문자 배열로 받아옴 -> scanf 사용
 */

#include <iostream>
#include <queue>
using namespace std;

int main(){
    char digits[11] = {};
    scanf("%s", digits);

    priority_queue<char, vector<char>, less<char> > pq;

    for(int i = 0; digits[i] != '\0'; i++){
        pq.push(digits[i]);
    }
    
    while(!pq.empty()){
        printf("%c", pq.top());
        pq.pop();
    }
}