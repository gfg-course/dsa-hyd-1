#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dy[8] = {-1, +1, -2, +2, -2, +2, -1, +1};

bool isSafe(int i, int j, int n, vector<vector<bool>> &vis) {
    return i >= 0 && i < n && j >= 0 && j < n && !vis[i][j];
}

// TC: O(n^2)
// AS: O(n^2)
int minStepsByKnight(int n, pair<int, int> start, pair<int, int> target) {

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool> (n, false));

    q.push(start);
    int result = 0;

    while (!q.empty()) {
        int sz = q.size();

        while (sz--) {
            auto curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            if (i == target.first and j == target.second) {
                return result;
            }

            for (int k = 0; k < 8; k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if (isSafe(new_i, new_j, n, vis)) {
                    vis[new_i][new_j] = true;
                    q.push({new_i, new_j});
                }
            }
        }

        result++;
    }

    return -1;
}

int main() {
    
    cout << minStepsByKnight(6, {3, 4}, {0, 0}) << endl;
}