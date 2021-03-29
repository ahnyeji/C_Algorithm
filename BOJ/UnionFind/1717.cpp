/*  BOJ - 1717 : 집합의 표현
    29.March.2021 
 */

/*  [Union Find (Disjoint Set)]
    - Path Compression : 6320KB / 36ms
    - Union by Rank : 9828KB / 44ms (rank 저장하기 위한 배열 사용하므로 메모리 더 필요)
 */
#include <iostream>

using namespace std;

int n, m;
int p[1000001]; // 대표자 배열

int find(int x) { // 대표자 찾기
    if(x == p[x]) return x;
    return p[x] = find(p[x]); // 최적화; 경로 압축 (path compression)
}

void merge(int x, int y) { // union (두 집합 합치기; union이 공용체 예약어이므로 사용 불가)
    x = find(x); // x가 속한 집합의 대표자 찾기
    y = find(y); // y가 속한 집합의 대표자 찾기
    if(x == y) return; // 대표자가 같다면 같은 집합

    p[x] = y;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) { // make set : 대표자 배열 초기화 (자기 자신만 속한 집합)
        p[i] = i;
    }

    int op, a, b;
    for(int i = 0; i < m; i++) {
        cin >> op >> a >> b;
        if(op == 0) merge(a, b); // 0은 union 연산
        else cout << (find(a) == find(b) ? "YES\n" : "NO\n");
    }
}

/*
#include <iostream>

using namespace std;

int p[1000001];
int r[1000001];

int find(int x) {
    if(x == p[x]) return x;
    return find(p[x]);
}

void merge(int x, int y) { // 최적화; union by rank (rank=깊이 큰 트리에 작은 트리 붙이기)
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(r[x] == r[y]) r[y]++; // 깊이 같으면 둘 중 하나의 깊이 1 증가
    
    // 깊이 큰 쪽에 작은 쪽 붙이기
    if(r[x] > r[y]) p[y] = x;
    else p[x] = y;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) { // make set : 대표자 배열 초기화
        p[i] = i;
        r[i] = 1; // 깊이 모두 1로 초기화
    }

    int op, a, b;
    for(int i = 0; i < m; i++) {
        cin >> op >> a >> b;
        if(op == 0) merge(a, b);
        else cout << (find(a) == find(b) ? "YES\n" : "NO\n");
    }
}
*/