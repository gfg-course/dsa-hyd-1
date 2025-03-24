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

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// TC: O(n^2)
// AS: O(n)
Node* buildTreeUtil(vector<int> &inorder, vector<int> &postorder, 
                    int inStart, int inEnd, int &postIdx) {

    if (inStart > inEnd) {
        return NULL;
    }

    Node* root = new Node(postorder[postIdx]);
    postIdx--;

    // Find the root value in inorder.
    int inIdx = inStart;
    for (int i = inStart + 1; i <= inEnd; i++) {
        if (inorder[i] == root->data) {
            inIdx = i;
            break;
        }
    }

    root->right = buildTreeUtil(inorder, postorder, inIdx + 1, inEnd, postIdx);
    root->left = buildTreeUtil(inorder, postorder, inStart, inIdx - 1, postIdx);

    return root;
}

Node* buildTreeUsingPostOrderAndInorder(vector<int> inorder, vector<int> postorder) {

    int n = inorder.size();
    if (n == 0) {
        return NULL;
    }

    int postIdx = n - 1;
    return buildTreeUtil(inorder, postorder, 0, n - 1, postIdx);
}


int main() {

    Node* root = buildTreeUsingPostOrderAndInorder({4, 2, 5, 1, 3, 6}, {4, 5, 2, 6, 3, 1});

    cout << "Post-order: ";
    postOrder(root);

    cout << endl;
    cout << "In-order: ";
    inOrder(root);
}