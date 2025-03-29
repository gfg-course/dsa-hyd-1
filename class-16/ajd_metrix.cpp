#include <bits/stdc++.h>
using namespace std;

void addUndirectedEdge(vector<vector<int>> &adj, int i, int j) {
    adj[i][j] = 1;
    adj[j][i] = 1;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V, vector<int> (V, 0));
    addUndirectedEdge(adj, 0, 1);
    addUndirectedEdge(adj, 0, 4);
    addUndirectedEdge(adj, 1, 2);
    addUndirectedEdge(adj, 2, 3);
    addUndirectedEdge(adj, 3, 4);
    addUndirectedEdge(adj, 1, 4);
    addUndirectedEdge(adj, 1, 3);

    for (auto i : adj) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}