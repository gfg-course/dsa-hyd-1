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

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


// TC: O(H)
// AS: O(H)
bool searchInBST(Node* root, int target) {
    if (root == NULL) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    if (target > root->data) {
        return searchInBST(root->right, target);
    }
    return searchInBST(root->left, target);
}

// TC: O(H)
// AS: O(1)
bool searchInBSTIterative(Node* root, int target) {

    while(root != NULL) {
        if (root->data == target) {
            return true;
        }

        if (target > root->data) {
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return false;
}


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

int getSmallestValue(Node* root) {
    // This will be never true.
    if (root == NULL) {
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

// TC: O(H)
// AS: O(H)
Node* deleteNode(Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }

    if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else {
        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }

        // childCount == 2
        int inorderSuccessor = getSmallestValue(root->right);
        root->data = inorderSuccessor;
        root->right = deleteNode(root->right, inorderSuccessor);
    }

    return root;
}

int main() {

}