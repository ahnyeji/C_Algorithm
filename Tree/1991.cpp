/*  BOJ - 1991 : 트리 순회
    18.February.2021
 */

/*  [Binary Tree]
    # Binary : 0 <= degree(차수; 자식 개수 / 간선 수) <= 2
    # Traversal(순회) -> root 위치에 따라 이름 붙여짐 (항상 left가 right보다 먼저 순회)
      - Preorder(전위) : root 위치가 "pre(전)"이므로 root -> left -> right
      - Inorder(중위) : root 위치가 "in(중)"이므로 left -> root -> right
      - Postorder(후위) : root 위치가 "post(후)"이므로 left -> right -> root
 */

#include <iostream>

using namespace std;

int N;
int tree[26][2];

void preOrder(int p){ // PreOrder : root -> left -> right
    cout << (char)('A' + p); // root(parent)
    if(tree[p][0] > 0){ // left
        preOrder(tree[p][0]);
    }
    if(tree[p][1] > 0){ // right
        preOrder(tree[p][1]);
    }
}

void inOrder(int p){ // InOrder : left -> root -> right
    if(tree[p][0] > 0){ // left
        inOrder(tree[p][0]);
    }
    cout << (char)('A' + p); // root(parent)
    if(tree[p][1] > 0){ // right
        inOrder(tree[p][1]);
    }
}

void postOrder(int p){ // PostOrder : left -> right -> root
    if(tree[p][0] > 0){ // left
        postOrder(tree[p][0]);
    }
    if(tree[p][1] > 0){ // right
        postOrder(tree[p][1]);
    }
    cout << (char)('A' + p); // root(parent)
}

int main(){
    cin >> N;

    char p, l, r;
    for(int i = 0; i < N; i++){
        cin >> p >> l >> r;
        if(l != '.') tree[p - 'A'][0] = l - 'A'; // tree[parent][0] : left child
        if(r != '.') tree[p - 'A'][1] = r - 'A'; // tree[parent][1] : right child
    }

    preOrder(0);
    cout << "\n";

    inOrder(0);
    cout << "\n";
    
    postOrder(0);
    cout << "\n";
    
}