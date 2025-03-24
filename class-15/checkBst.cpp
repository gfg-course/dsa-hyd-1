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



Node* insertIntoBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (root->data == val) {
        return root;
    }

    if (val > root->data) {
        root->right = insertIntoBST(root->right, val);
    } else {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}

bool isBstUtil(Node* root, int low, int high) {
    if (root == NULL) {
        return true;
    }

    return 
        root->data >= low && root->data <= high &&
        isBstUtil(root->left, low, root->data - 1) &&
        isBstUtil(root->right, root->data + 1, high);
}

// TC: O(n)
// AS: O(h)
bool isBst(Node* root) {
    return isBstUtil(root, -1e9, 1e9);
}

int main() {
    Node* root = new Node(10);
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 50);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 9);
    root = insertIntoBST(root, 40);
    root = insertIntoBST(root, 100);

    cout << isBst(root) << endl;

    root->data = 6;
    cout << isBst(root);
}