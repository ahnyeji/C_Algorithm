/*  BOJ - 1068 : 트리
    19.February.2021
 */

/*  [Tree]
    # 트리 입력이 항상 순서대로 주어지지 않음 (예제가 그런 것 뿐)
      => root가 0이 아닐 수 있다 (이 부분 놓쳐서 오답)
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > tree;
int cnt;

void findLeaf(int idx){
    int len = tree[idx].size();
    if(len == 0){
        cnt++;
        return;
    }
    for(int i = 0; i < len; i++){
        findLeaf(tree[idx][i]);
    }
}

int main(){
    int N;
    cin >> N;

    tree.resize(N, vector<int>(0));
    int root;

    vector<int> p(N);

    for(int i = 0; i < N; i++){
        cin >> p[i];
        if(p[i] == -1) root = i;
        else tree[p[i]].push_back(i);
    }

    int node;
    cin >> node;
    if(p[node] == -1){ // root can be any number (not fixed to 0)
        cout << 0;
        return 0;
    }
    tree[node].clear();
    
    int len = tree[p[node]].size();
    for(int i = 0; i < len; i++){
        if(tree[p[node]][i] == node){
            tree[p[node]].erase(tree[p[node]].begin() + i);
            break;
        }
    }

    findLeaf(root);
    cout << cnt;
}