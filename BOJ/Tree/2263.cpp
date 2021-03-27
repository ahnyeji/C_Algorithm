/*  BOJ - 2263 : 트리의 순회
    23.February.2021
    (20.February.2021 Live Problem Solving)
 */

/*  [Tree]
    # root : PostOrder의 마지막 원소 (PostOrder : left | right | "root")
    # left : InOrder에서 root 이전 원소 (InOrder : "left" | root | right)
    # right : InOrder에서 root 이후 원소 (InOrder : left | root | "right")
    => SubTree의 root를 PostOrder에서 찾고 하위 SubTree(left, right)는 InOrder에서 root 찾은 후 시작&끝 인덱스로 나누기
    => InOrder에서 root 찾을 때 매 번 반복문으로 찾는 것 보다 미리 인덱스를 저장해두면 시간 효율 높일 수 있음
 */

#include <iostream>
using namespace std;

int inO[100001];
int inOidx[100001]; // save InOrder elements' index -> faster search
int postO[100001];

void findroot(int starti, int endi, int startp, int endp){
    if(starti > endi) return; // not tree
    cout << postO[endp] << " "; // root of sub-tree
    if(starti == endi) return; // no more sub-tree (leaf node)
    int idx = inOidx[postO[endp]]; // index of sub-tree's root at inOrder
    int postnext = startp + idx - starti - 1; // idx - starti : length
    findroot(starti, idx - 1, startp, postnext); // left sub-tree
    findroot(idx + 1, endi, postnext + 1, endp - 1); // right sub-tree
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> inO[i];
        inOidx[inO[i]] = i; // save InOrder elemenets' index
    }
    for(int i = 0; i < n; i++){
        cin >> postO[i];
    }
    findroot(0, n - 1, 0, n - 1);
}

/* search inOrder index using for-loop (search : O(N))
#include <iostream>
using namespace std;

int n;
int inO[100001];
int postO[100001];

void findroot(int starti, int endi, int startp, int endp){
    cout << postO[endp] << " ";
    if(starti >= endi) return;

    // search root index at InOrder
    int idx = starti;
    while(inO[idx] != postO[endp]){
        idx++;
    }

    int postnext = startp + idx - starti - 1;
    if(idx > starti) findroot(starti, idx - 1, startp, postnext); // left sub-tree
    if(idx < endi) findroot(idx + 1, endi, postnext + 1, endp - 1); // right sub-tree
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> inO[i];
    }

    for(int i = 0; i < n ; i++){
        cin >> postO[i];
    }

    findroot(0, n - 1, 0, n - 1);
}

*/