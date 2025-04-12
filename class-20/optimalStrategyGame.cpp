#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// AS: O(n^2)
int maxScoreInGameUtil(vector<int> &arr, int i, int j, vector<vector<int>>& memo) {
    if (i > j) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int option1 = arr[i] + maxScoreInGameUtil(arr, i + 2, j, memo); // i -> i+1
    int option2 = arr[i] + maxScoreInGameUtil(arr, i + 1, j - 1, memo); // i -> j
    int scoreIfPicki = min(option1, option2);

    int option3 = arr[j] + maxScoreInGameUtil(arr, i + 1, j - 1, memo); // j -> i
    int option4 = arr[j] + maxScoreInGameUtil(arr, i, j - 2, memo); // j -> j-1
    int scoreIfPickj = min(option3, option4);

    memo[i][j] = max(scoreIfPicki, scoreIfPickj);
    return memo[i][j];
}

int maxScoreInGame(vector<int> coins) {
    int n = coins.size();

    vector<vector<int>> memo(n, vector<int> (n, -1));
    return maxScoreInGameUtil(coins, 0, n - 1, memo);
}

int main() {
    cout << maxScoreInGame({5, 3, 7, 10}) << endl;
    cout << maxScoreInGame({8, 15, 3, 7}) << endl;
}