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

// TC: O(n)
// AS: O(min(n, k))
void getNodesAtDistanceKFromRoot(Node* root, int k, vector<int> &result) {
    if (root == NULL || k < 0) {
        return;
    }

    if (k == 0) {
        result.push_back(root->data);
        return;
    }

    getNodesAtDistanceKFromRoot(root->left, k - 1, result);
    getNodesAtDistanceKFromRoot(root->right, k - 1, result);
}

void getPathUtil(Node* root, int target, vector<Node*> &currPath, vector<Node*> &path) {
    if (root == NULL || !path.empty()) {
        return;
    }

    currPath.push_back(root);
    if (root->data == target) {
        path = currPath;
        return;
    }

    getPathUtil(root->left, target, currPath, path);
    getPathUtil(root->right, target, currPath, path);

    currPath.pop_back();
}

// TC: O(n)
// AS: O(H)
vector<Node*> getPath(Node* root, int target) {
    vector<Node*> currPath;
    vector<Node*> path;

    getPathUtil(root, target, currPath, path);
    return path;
}

// TC: O(n)
// AS: O(n)
vector<int> getNodesAtDistanceKFromTarget(Node* root, int target, int k) {

    vector<int> result;

    vector<Node*> path = getPath(root, target); // TC, AS: O(n), O(n)
    int pathSize = path.size();

    // If target doesn't exist.
    if (pathSize == 0) {
        return {};
    }

    getNodesAtDistanceKFromRoot(path[pathSize - 1], k, result); // O(n), O(min(n, k))

    if (pathSize - k - 1 >= 0) {
        result.push_back(path[pathSize - k - 1]->data);
    }

    // O(n), O(min(n, k))
    for (int i = pathSize - 2; i >= 0; i--) {
        if (path[i + 1] == path[i]->left) {
            getNodesAtDistanceKFromRoot(path[i]->right, k - 2, result);
        } else {
            getNodesAtDistanceKFromRoot(path[i]->left, k - 2, result);
        }
        k--;
    }

    return result;
}

int main() {
    
    vector<Node*> nodes;
    nodes.push_back(new Node(-1));
    for (int i = 1; i <= 8; i++) {
        nodes.push_back(new Node(i));
    }

    nodes[1]->left = nodes[2];
    nodes[1]->right = nodes[3];

    nodes[2]->left = nodes[4];
    nodes[2]->right = nodes[5];

    nodes[4]->left = nodes[6];
    nodes[4]->right = nodes[7];

    nodes[6]->left = nodes[8];

    vector<int> result = getNodesAtDistanceKFromTarget(nodes[1], 6, 3);
    for (int i : result) {
        cout << i << " ";
    }
}