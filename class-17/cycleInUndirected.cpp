#include <bits/stdc++.h>
using namespace std;

bool detectCycleUndirectedUtil(vector<vector<int>> &adj, int curr, int parent, vector<bool> &vis) {

    vis[curr] = true;

    for (int neighbor : adj[curr]) {
        if (vis[neighbor] && neighbor != parent) {
            return true;
        }
        if (!vis[neighbor] && detectCycleUndirectedUtil(adj, neighbor, curr, vis)) {
            return true;
        }
    }

    return false;
}

// TC: O(V + E)
// AS: O(V)
bool detectCycleUndirected(vector<vector<int>> adj) {

    int V = adj.size();

    vector<bool> vis(V, false);
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detectCycleUndirectedUtil(adj, i, -1, vis)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    
    cout << detectCycleUndirected({{1},
                                    {0, 2, 4},
                                    {1, 3},
                                    {2, 4},
                                    {1, 3}}) << endl;

    cout << detectCycleUndirected({{1},
                                    {0, 2, 4},
                                    {1, 3},
                                    {2},
                                    {1}}) << endl;
}