/*  BOJ - 3584 : 가장 가까운 공통 조상
    19.February.2021
 */

/*  [Tree]
    # reverseTree[child] = parent : 자식은 하나의 부모만 가짐 & 부모를 구해야 함
    # 두 노드의 조상 찾아 리스트화 (해당 노드의 가까운 조상 -> root)
      => 자기 자신도 포함
    # 두 리스트의 마지막에는 root가 들어있음
      => root 넣지 않아서 오답
    # 리스트의 마지막부터 서로 다른 원소가 나올 때까지 비교
      => 서로 다른 원소가 나오기 직전의 원소가 가장 가까운 공통 조상
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, N, A, B;

    cin >> T;
    while(T--){
        cin >> N;
        vector<int> reverseTree(N + 1, 0);

        for(int i = 1; i < N; i++){
            cin >> A >> B;
            reverseTree[B] = A;
        }
        
        cin >> A >> B;

        vector<int> pA;
        vector<int> pB;

        while(reverseTree[A] > 0){ // A's ancestor
            pA.push_back(A);
            A = reverseTree[A];
        }
        pA.push_back(A); // add root

        while(reverseTree[B] > 0){ // B's ancestor
            pB.push_back(B);
            B = reverseTree[B];
        }
        pB.push_back(B); // add root

        int alen = pA.size() - 1; // last index of pA
        int blen = pB.size() - 1; // last index of pB

        while(alen > -1 && blen > -1 && pA[alen] == pB[blen]){ // find nearest ancestor
            alen--;
            blen--;
        }
        
        if(alen == -1) cout << pA[0] << "\n"; // A is ancestor of B
        else cout << pA[alen + 1] << "\n";
    }
}