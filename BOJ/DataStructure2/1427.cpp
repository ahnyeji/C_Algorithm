/*  BOJ - 1427 : 소트인사이드
    02.February.2021
 */

/*  [Selection Sort 구현]
    # Selection Sort
        - 원소 최대 10개(숫자 범위 최대 1억)이므로 N^2 알고리즘도 무리 없음
    # 입력
        - 숫자가 아닌 하나의 문자열로 입력 처리 (길이 미리 알 수 없으므로 %1d 사용 불가)
        - 문자열 한 번 받아오므로 cin.tie(NULL) 필요 없음
        - 문자열의 각 문자 활용 위해 문자 배열로 받아옴 -> scanf 사용
    # 출력
        - 한 번에 문자열로 출력 가능
 */

#include <iostream>
#include <queue>
using namespace std;

int main(){
    char digits[11] = {};
    scanf("%s", digits);

    for(int i = 0; digits[i] != '\0'; i++){
        char d = digits[i];

        int maxIdx = i;
        for(int j = i; digits[j] != '\0'; j++){
            if(digits[maxIdx] < digits[j]){
                maxIdx = j;
            }
        }

        digits[i] = digits[maxIdx];
        digits[maxIdx] = d;
    }
    
    printf("%s", digits);
}