/*  BOJ - 13305 : 주유소
    06.March.2021
    (06.March.2021 Live Problem Solving)
 */

/*  [Greedy]
    # 현재까지의 주유소 리터당 가격 중 최소 값을 더하는 것이 탐욕적
 */

#include <iostream>

using namespace std;

int itoj[100000];
int price[100000];

int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N - 1; i++){
    cin >> itoj[i];
  }

  for(int i = 0; i < N; i++){
    cin >> price[i];
  }

  long long tot = 0;
  long long min = 1000000000;
  for(int i = 0; i < N - 1; i++){
    min = min > price[i] ? price[i] : min; // find minimum price
    tot += min * itoj[i];
  }
  cout << tot << "\n";
}
