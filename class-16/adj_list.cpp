#include <bits/stdc++.h>
using namespace std;

void addUndirectedEdge(vector<vector<int>> &adj, int i, int j) {
    adj[i].push_back(j);
    adj[j].push_back(i);
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    addUndirectedEdge(adj, 0, 1);
    addUndirectedEdge(adj, 0, 4);
    addUndirectedEdge(adj, 1, 2);
    addUndirectedEdge(adj, 2, 3);
    addUndirectedEdge(adj, 3, 4);
    addUndirectedEdge(adj, 1, 4);
    addUndirectedEdge(adj, 1, 3);

    
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}