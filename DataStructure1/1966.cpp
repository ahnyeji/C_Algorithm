#include <iostream>

#include <queue>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        int N, M;
        cin >> N >> M;
        queue<pair<int, int> > docs;
        for(int i = 0; i < N; i++){
            int prior;
            cin >> prior;
            docs.push(make_pair(i, prior));
        }
        int cnt = 0;
        while(!docs.empty()){
            int curP = docs.front().second;
            int bigger = 0;
            for(int i = 0; i < N; i++){
                docs.push(docs.front());
                docs.pop();
                if(docs.front().second > curP){
                    bigger++;
                }
            }
            if(bigger){
                docs.push(docs.front());
                docs.pop();
            }
            else{
                if(docs.front().first != M){
                    docs.pop();
                    N--;
                    cnt++;
                }
                else{
                    cout << ++cnt << "\n";
                    break;
                }
            }
        }
    }
}