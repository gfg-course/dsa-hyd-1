#include <bits/stdc++.h>
using namespace std;

// TC: O(n * value)
// AS: O(n * value)
int getMinCoinsUtil(int i, vector<int> &coins, int value,
                    vector<vector<int>> &memo) {
    if (value == 0) {
        return 0;
    }
    if (i == coins.size()) {
        return 1e9;
    }
    if (memo[i][value] != -1) {
        return memo[i][value];
    }

    if (coins[i] > value) {
        memo[i][value] = getMinCoinsUtil(i + 1, coins, value, memo);
        return memo[i][value];
    }

    int consider = 1 + getMinCoinsUtil(i, coins, value - coins[i], memo);
    int skip = getMinCoinsUtil(i + 1, coins, value, memo);

    memo[i][value] = min(consider, skip);
    return memo[i][value];
}

int getMinCoins(vector<int> coins, int value) {

    int n = coins.size();
    vector<vector<int>> memo(n, vector<int> (value + 1, -1));

    int result = getMinCoinsUtil(0, coins, value, memo);
    if (result >= 1e9) {
        return -1;
    }
    return result;
}

int main() {
    cout << getMinCoins({2, 5, 3, 6}, 10) << endl;
    cout << getMinCoins({3, 6, 3}, 5) << endl;
}