#include <bits/stdc++.h>
using namespace std;

vector<int> getSingleSourceShortestPaths(vector<vector<pair<int, int>>> adj, int src) {

    int V = adj.size();

    vector<int> dist(V, 1e9);
    dist[src] = 0;

    // Defining a Min-Heap.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[src], src});

    while (!pq.empty()) {

        auto curr = pq.top();
        pq.pop();

        int d = curr.first;
        int u = curr.second;

        for (pair<int, int> neighbor : adj[u]) {
            int wtUV = neighbor.second;
            int v = neighbor.first;

            if (d + wtUV < dist[v]) {
                dist[v] = d + wtUV;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


void addUndirectedEdge(int u, int v, int w, vector<vector<pair<int, int>>> &adj) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int main() {
    
    int V = 9;
    vector<vector<pair<int, int>>> adj(9);
    addUndirectedEdge(0, 1, 4, adj);
    addUndirectedEdge(0, 7, 8, adj);
    addUndirectedEdge(1, 7, 11, adj);
    addUndirectedEdge(1, 2, 8, adj);
    addUndirectedEdge(7, 8, 7, adj);
    addUndirectedEdge(2, 8, 2, adj);
    addUndirectedEdge(8, 6, 6, adj);
    addUndirectedEdge(7, 6, 1, adj);
    addUndirectedEdge(2, 5, 4, adj);
    addUndirectedEdge(6, 5, 2, adj);
    addUndirectedEdge(2, 3, 7, adj);
    addUndirectedEdge(3, 5, 14, adj);
    addUndirectedEdge(3, 4, 9, adj);
    addUndirectedEdge(5, 4, 10, adj);

    vector<int> result = getSingleSourceShortestPaths(adj, 0);

    for (int i = 0; i < V; i++) {
        cout << i << " : " << result[i] << endl;
    }
}