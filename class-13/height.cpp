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

// TC: O(N)
// AS: O(H)
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSubtreeHeight = height(root->left);
    int rightSubtreeHeight = height(root->right);

    return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
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

    cout << height(n1);
}