#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    priority_queue<int, vector<int> > pq;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(x){
            pq.push(x);
        }
        else{
            if(pq.empty()){
                cout << "0\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}