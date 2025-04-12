#include <bits/stdc++.h>
using namespace std;

set<int> getElementsAtIndex(vector<int> &arr, vector<int> &indexes) {
    set<int> s;
    for (int i : indexes) {
        s.insert(arr[i]);
    }

    return s;
}

void dfs(int cur, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &result) {
    if (vis[cur]) {
        return;
    }

    vis[cur] = true;
    result.push_back(cur);

    for (int i : adj[cur]) {
        dfs(i, adj, vis, result);
    }
}

// TC: O(n + goodPairs.size())
// AS: O(n)
bool permutationSwaps(vector<int> A, vector<int> B, vector<vector<int>> goodPairs) {

    int n = A.size();

    vector<vector<int>> adj(n);

    for (int i = 0; i < goodPairs.size(); i++) {
        goodPairs[i][0]--;
        goodPairs[i][1]--;

        adj[goodPairs[i][0]].push_back(goodPairs[i][1]);
        adj[goodPairs[i][1]].push_back(goodPairs[i][0]);
    }

    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vector<int> indexes;
            dfs(i, adj, vis, indexes);

            set<int> sA = getElementsAtIndex(A, indexes);
            set<int> sB = getElementsAtIndex(B, indexes);

            if (sA != sB) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    
}