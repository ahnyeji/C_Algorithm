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
    for(int i = 1; i <= n; i++) { // 대표자 배열 초기화 (자기 자신만 속한 집합)
        p[i] = i;
    }

    int op, a, b;
    for(int i = 0; i < m; i++) {
        cin >> op >> a >> b;
        if(op == 0) merge(a, b); // 0은 union 연산
        else cout << (find(a) == find(b) ? "YES\n" : "NO\n");
    }
}