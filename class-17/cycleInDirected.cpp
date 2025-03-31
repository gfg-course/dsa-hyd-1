#include <bits/stdc++.h>
using namespace std;

bool detectCycleDirectedUtil(vector<vector<int>> &adj, int curr, vector<bool> &vis, vector<bool> &recStack) {

    vis[curr] = true;
    recStack[curr] = true;

    for (int neighbor : adj[curr]) {
        if (recStack[neighbor]) {
            return true;
        }
        if (!vis[neighbor] && detectCycleDirectedUtil(adj, neighbor, vis, recStack)) {
            return true;
        }
    }

    recStack[curr] = false;
    return false;
}

// TC: O(V+E)
// AS: O(V)
bool detectCycleDirected(vector<vector<int>> adj) {

    int V = adj.size();
    vector<bool> vis(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detectCycleDirectedUtil(adj, i, vis, recStack)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    
    cout << detectCycleDirected({{},
                                 {2, 3},
                                 {3},
                                 {}}) << endl;

    cout << detectCycleDirected({{},
                                 {2},
                                 {3},
                                 {4},
                                 {5},
                                 {2}}) << endl;
}