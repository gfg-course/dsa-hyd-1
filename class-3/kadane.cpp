#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
int maxSumSubarray(vector<int> arr) {
    int n = arr.size();

    vector<int> maxTillCurrent(n);
    int result = arr[0];
    maxTillCurrent[0] = arr[0];

    for (int i = 1; i < n; i++) {
        maxTillCurrent[i] = max(arr[i], arr[i] + maxTillCurrent[i - 1]);
        result = max(result, maxTillCurrent[i]);
    }

    return result;
}

// TC: O(n)
// AS: O(1)
int maxSumSubarrayOptimized(vector<int> arr) {
    int n = arr.size();

    int maxTillCurrent = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        maxTillCurrent = max(arr[i], arr[i] + maxTillCurrent);
        result = max(result, maxTillCurrent);
    }

    return result;
}

int main() {

    cout << maxSumSubarrayOptimized({1, 2, 3, -2, 5}) << endl;
    cout << maxSumSubarrayOptimized({-1, -2, -3, -4}) << endl;
    cout << maxSumSubarrayOptimized({1, -2, 3, -5, -6, 1}) << endl;
}