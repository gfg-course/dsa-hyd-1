#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m)
// AS: O(n * m)
int lcsUtil(string &s1, int i, string &s2, int j, vector<vector<int>> &memo) {
    if (i == s1.length() || j == s2.length()) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (s1[i] == s2[j]) {
        memo[i][j] = 1 + lcsUtil(s1, i + 1, s2, j + 1, memo);
        return memo[i][j];
    }

    memo[i][j] = max(lcsUtil(s1, i + 1, s2, j, memo), lcsUtil(s1, i, s2, j + 1, memo));
    return memo[i][j];
}

int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> memo(n, vector<int> (m, -1));

    return lcsUtil(s1, 0, s2, 0, memo);
}

// TC: O(nm)
// AS: O(nm)
int lcsBottomUp(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    // Cater to the base-cases from top-down
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j < m; j++) {
        dp[0][j] = 0;
    }

    // TODO: optimize the space by storing only the immediate previous row of dp[][].
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[i - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    cout << lcs("ABCDGH", "AEDFHR");
}