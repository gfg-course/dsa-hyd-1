#include <bits/stdc++.h>
using namespace std;

void dfsUtil(vector<vector<int>> &adj, int node, vector<bool> &vis, vector<int> &result) {
    vis[node] = true;
    result.push_back(node);

    for (int adjNode : adj[node]) {
        if (!vis[adjNode]) {
            dfsUtil(adj, adjNode, vis, result);
        }
    }
}

// TC: O(V+E)
// AS: O(V)
vector<int> dfs(vector<vector<int>> adj) {

    int V = adj.size();
    vector<bool> vis(V, false);

    vector<int> result;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsUtil(adj, i, vis, result);
        }
    }
    return result;
}

int main() {

    vector<int> result = dfs({
                            {1, 2},
                            {0, 4, 3},
                            {0, 4},
                            {1, 4, 5},
                            {2, 1, 3, 5},
                            {3, 4},
                            {}});

    for (int i : result) {
        cout << i << " ";
    }
}