//
//  main.cpp
//  1991 트리 순회
//
//  Created by Sun on 2023/11/18.
//

#include <iostream>
#include <vector>

using namespace std;

struct node {
    char value;
    node* left = NULL;
    node* right = NULL;
};

void preorder(node* n);
void inorder(node* n);
void postorder(node* n);

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<node> tree(N);
    
    for (int i = 0; i < N; i++) {
        char v, l, r;
        cin >> v >> l >> r;
        
        tree[v-'A'].value = v;
        if (l != '.')   tree[v-'A'].left = &tree[l-'A'];
        if (r != '.')   tree[v-'A'].right = &tree[r-'A'];
    }
    node *root = &tree[0];
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
    
    return 0;
}

void preorder(node* n) {    // root -> left -> right
    cout << n->value;
    if (n->left)    // != NULL
        preorder(n->left);
    if (n->right)
        preorder(n->right);
}

void inorder(node* n) {     // left -> root -> right
    if (n->left)
        inorder(n->left);
    cout << n->value;
    if (n->right)
        inorder(n->right);
}

void postorder(node* n) {     // left -> right -> root
    if (n->left)
        postorder(n->left);
    if (n->right)
        postorder(n->right);
    cout << n->value;
}

// 트리의 각 node를 표현하는 구조체를 정의하고, node들을 담는 벡터로 tree를 구현했다.
// 트리의 노드를 채울 때에는 A~Z가 0~25에 대응되도록 하기 위해 char-'A'로 해당 인덱스를 구해줌!
// 각 노드의 왼쪽 자식과 오른쪽 자식은 또 다른 노드 구조체의 주소를 담기 위해 &tree[l-'A']로 주소 반환하기..~

// ++) 포인터 배열
// vector 대신에 node* tree = new node[N]; 이렇게 동적할당으로 구해줄 수도 있지만 메모리 해제(delete[] tree)를 해줘야 할 것.
// malloc으로 한다면 node* tree = (node*)malloc(sizeof(node) * N); && free(tree);
