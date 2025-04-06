#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m)
// AS: O(n * m)
int editDistanceUtil(string &s1, int i, string &s2, int j,
                    vector<vector<int>> &memo) {
    if (i == s1.length()) {
        return s2.length() - j;
    }
    if (j == s2.length()) {
        return s1.length() - i;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (s1[i] == s2[j]) {
        memo[i][j] = editDistanceUtil(s1, i + 1, s2, j + 1, memo);
        return memo[i][j];
    }

    int insert = 1 + editDistanceUtil(s1, i, s2, j + 1, memo);
    int del = 1 + editDistanceUtil(s1, i + 1, s2, j, memo);
    int replace = 1 + editDistanceUtil(s1, i + 1, s2, j + 1, memo);

    memo[i][j] = min({insert, del, replace});
    return memo[i][j];
}

int editDistance(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> memo(n, vector<int> (m, -1));

    return editDistanceUtil(s1, 0, s2, 0, memo);
}

int main() {
    
}