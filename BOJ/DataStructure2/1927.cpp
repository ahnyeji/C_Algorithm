/*  BOJ - 1927 : 최소 힙
    01.February.2021
 */

/*  [Min Heap 구현]
    # 시간초과
    cin.tie(NULL); // cin과 cout의 tie 해제 (입출력 순서 보장 불가)
    ios_base::sync_with_stdio(false); // C의 stdio와 동기화 해제 -> C++ 독립 버퍼 사용 -> printf, scanf 사용 불가
    미사용 시 시간초과, 사용 시 성공(16ms)
 */

#include <iostream>
using namespace std;

int heap[100001];
int sizeIdx = 0;
void insert(int x){
    heap[++sizeIdx] = x;
    int child = sizeIdx;
    while(1){
        if(child == 1) return;
        int parent = child / 2;
        if(heap[child] < heap[parent]){
            int tmp = heap[child];
            heap[child] = heap[parent];
            heap[parent] = tmp;
            child = parent;
        }
        else{
            return;
        }
    }
}

void remove(){
    if(sizeIdx == 0){
        cout << "0\n";
        return;
    }
    cout << heap[1] << "\n";
    heap[1] = heap[sizeIdx];
    heap[sizeIdx--] = 0;
    int parent = 1;
        while(1){
            int left = parent * 2;
            int right = parent * 2 + 1;
            if(left > sizeIdx) return;
            int tochange;
            if(right > sizeIdx){
                if(heap[parent] > heap[left]){
                    tochange = left;
                }
                else return;
            }
            else{
                if(heap[parent] <= heap[left]){
                    if(heap[parent] <= heap[right]) return;
                    else{
                        tochange = right;
                    }
                }
                else{
                    if(heap[parent] <= heap[right]){
                        tochange = left;
                    }
                    else{
                        tochange = heap[left] < heap[right] ? left : right;
                    }
                }
            }
            int tmp = heap[parent];
            heap[parent] = heap[tochange];
            heap[tochange] = tmp;
            parent = tochange;
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(x){
            insert(x);
        }
        else{
            remove();
        }
    }
}