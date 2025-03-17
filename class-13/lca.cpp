#include <bits/stdc++.h>
using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// TODO: find the LCA using the path-based approach.

// TC: O(n)
// AS: O(H)
Node* lca(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLca = lca(root->left, n1, n2);
    Node* rightLca = lca(root->right, n1, n2);

    if (leftLca != NULL && rightLca != NULL) {
        return root;
    }

    if (leftLca != NULL) {
        return leftLca;
    }
    return rightLca;
}

int main() {

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->right = n6;

    n4->left = n7;
    n4->right = n8;
    
    cout << lca(n1, 7, 5)->data << endl;
    cout << lca(n1, 2, 7)->data << endl;
    cout << lca(n1, 7, 8)->data << endl;
    cout << lca(n1, 8, 6)->data << endl;
}