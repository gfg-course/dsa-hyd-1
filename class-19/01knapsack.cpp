#include <bits/stdc++.h>
using namespace std;

// TC: O(n * W)
// AS: O(n * W)
int getMaxValueUtil(int i, vector<int> &vals, vector<int> &wts, int W,
                    vector<vector<int>> &memo) {
    
    if (i == vals.size() || W == 0) {
        return 0;
    }
    if (memo[i][W] != -1) {
        return memo[i][W];
    }

    if (wts[i] > W) {
        memo[i][W] = getMaxValueUtil(i + 1, vals, wts, W, memo);
        return memo[i][W];
    }

    int consider = vals[i] + getMaxValueUtil(i + 1, vals, wts, W - wts[i], memo);
    int skip = getMaxValueUtil(i + 1, vals, wts, W, memo);

    memo[i][W] = max(consider, skip);
    return memo[i][W];
}

int getMaxValue(vector<int> vals, vector<int> wts, int W) {
    int n = vals.size();

    vector<vector<int>> memo(n, vector<int> (W + 1, -1));
    return getMaxValueUtil(0, vals, wts, W, memo);
}


// TC: O(n * W)
// AS: O(n * W)
int getMaxValueBottomUp(vector<int> vals, vector<int> wts, int W) {
    int n = vals.size();

    vector<vector<int>> dp(n + 1, vector<int> (W + 1));

    // Cater to the base-cases: array is empty || capacity is zero
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wts[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                int consider = vals[i - 1] + dp[i - 1][j - wts[i - 1]];
                int skip = dp[i - 1][j];

                dp[i][j] = max(consider, skip);
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= W; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[n][W];
}

int main() {
    cout << getMaxValue({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << getMaxValueBottomUp({60, 100, 120}, {10, 20, 30}, 50) << endl;
}