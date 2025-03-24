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

void pushAndMoveLeft(Node* node, stack<Node*> &s) {
    while (node != NULL) {
        s.push(node);
        node = node->left;
    }
}


// TODO: Try iterative postoder and preorder.
vector<int> iterativeInorder(Node *root) {

    if (root == NULL) {
        return {};
    }

    stack<Node*> s;
    vector<int> result;

    pushAndMoveLeft(root, s);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();

        result.push_back(curr->data);

        pushAndMoveLeft(curr->right, s);
    }

    return result;
}


int main() {

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->right = n6;

    inOrder(n1);

    cout << endl;

    vector<int> result = iterativeInorder(n1);
    for (int i : result) {
        cout << i << " ";
    }
}