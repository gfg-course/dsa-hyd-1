#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, +0, +1, +1, +1, +0, -1};
int dy[8] = {+0, +1, +1, +1, +0, -1, -1, -1};

void dfs(int i, int j, vector<vector<int>> &arr) {
    if (i < 0 || i >= arr.size() || j < 0 || j >= arr[i].size() || 
        arr[i][j] == 0) {
        return;
    }

    arr[i][j] = 0;

    for (int k = 0; k < 8; k++) {
        dfs(i + dx[k], j + dy[k], arr);
    }
}

// TC: O(n*m)
// AS: O(n*m)

int countIslands(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                dfs(i, j, arr);
                result++;
            }
        }
    }

    return result;
}

int main() {

    cout << countIslands({{0, 1, 1, 1, 0, 0, 0},
                          {0, 0, 1, 1, 0, 1, 0}}) << endl;

    cout << countIslands({{0, 1, 1, 1, 0, 0, 0},
                          {0, 0, 1, 1, 1, 1, 0}}) << endl;

    cout << countIslands({{0, 0},
                          {0, 0}}) << endl;

    cout << countIslands({{1, 1},
                          {1, 1}}) << endl;

    cout << countIslands({{1, 0},
                          {0, 1}}) << endl;
}