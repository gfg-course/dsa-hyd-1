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

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

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

// TC: O(N)
// AS: O(N)
vector<int> levelOrder(Node* root) {
    if (root == NULL) {
        return {};
    }

    vector<int> result;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        result.push_back(curr->data);
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }

    return result;
}

// TC: O(N)
// AS: O(N)
vector<vector<int>> levelOrderLevelByLevel(Node* root) {

    if (root == NULL) {
        return {};
    }

    vector<vector<int>> result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        vector<int> currLevel;
        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            Node* curr = q.front();
            q.pop();

            currLevel.push_back(curr->data);

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }

        result.push_back(currLevel);
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
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->right = n6;

    n4->left = n7;
    n4->right = n8;

    preOrder(n1);
    cout << endl;

    postOrder(n1);
    cout << endl;

    inOrder(n1);
    cout << endl;

    vector<int> levelOrderList = levelOrder(n1);
    for (int i : levelOrderList) {
        cout << i << " ";
    }
    cout << endl;

    vector<vector<int>> levelOrderLevelByLevelList = levelOrderLevelByLevel(n1);
    for (auto i : levelOrderLevelByLevelList) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

}