#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(vector<vector<int>> &adj, int u, vector<bool> &vis, vector<int> &result) {

    vis[u] = true;

    for (int v : adj[u]) {
        if (!vis[v]) {
            topologicalSortUtil(adj, v, vis, result);
        }
    }

    // Once all the neighbors are in the result, push the current node into the result.
    result.push_back(u);
}

// TC: O(V + E)
// AS: O(V)
vector<int> topologicalSort(vector<vector<int>> adj) {

    int V = adj.size();
    vector<int> result;
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            topologicalSortUtil(adj, i, vis, result);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

// TC: O(V + E)
// AS: O(V)
vector<int> topologicalSortUsingInDegrees(vector<vector<int>> adj) {

    int V = adj.size();

    vector<int> inDegrees(V, 0);
    for (int u = 0; u < V; u++) { // O(V + E)
        for (int v : adj[u]) {
            inDegrees[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) { // O(V)
        if (inDegrees[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) { // O(V + E)
        int u = q.front();
        q.pop();

        result.push_back(u);
        for (int v : adj[u]) {
            inDegrees[v]--;
            if (inDegrees[v] == 0) {
                q.push(v);
            }
        }
    }

    return result;
}

int main() {
    
    vector<int> result = topologicalSort({{1, 2, 3},
                                          {},
                                          {1, 3},
                                          {}});


    for (int i  : result) {
        cout << i << " ";
    }

    cout << endl;

    vector<int> result2 = topologicalSortUsingInDegrees({{1, 2, 3},
                                          {},
                                          {1, 3},
                                          {}});


    for (int i  : result) {
        cout << i << " ";
    }

    cout << endl;
}