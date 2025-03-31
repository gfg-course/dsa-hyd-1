#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, +0, +1, +0};
int dy[4] = {+0, +1, +0, -1};

bool isFresh(int i, int j, vector<vector<int>> &arr) {
    return i >= 0 and i < arr.size() and j >= 0 and j < arr[i].size() and arr[i][j] == 1;
}

// TC: TODO
int rottenOranges(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 2) {
                q.push({i, j});
            }
        }
    }
    
    int result = 0;

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto curr = q.front();
            q.pop();
            
            int i = curr.first;
            int j = curr.second;

            for (int k = 0; k < 4; k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if (isFresh(new_i, new_j, arr)) {
                    arr[new_i][new_j] = 2;
                    q.push({new_i, new_j});
                }
            }
        }
        result++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                return -1;
            }
        }
    }

    if (result == 0) {
        return 0;
    }

    return result - 1;
}

int main() {
    
    cout << rottenOranges({{0, 1, 2}, {0, 1, 2}, {2, 1, 0}, {1, 1, 1}}) << endl;
    cout << rottenOranges({{2, 2, 0, 1}}) << endl;
    cout << rottenOranges({{2, 2, 2}, {0, 2, 0}}) << endl;

}