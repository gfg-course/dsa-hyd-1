#include <bits/stdc++.h>
using namespace std;

/**
 * T(n, target) = T(n - 1, target) + T(n, target - X) where X is the avg of input elements.
 * AS: O(2^d) where d = max(N, target).
 * */
void getCombinationsWithSumUtil(vector<int> &arr, int index, int target, vector<int> &current,
                                vector<vector<int>> &result) {
    
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (index == arr.size()) {
        return;
    }
    if (target < 0) {
        return;
    }

    // Do not consider arr[index]
    getCombinationsWithSumUtil(arr, index + 1, target, current, result);

    // Conside arr[index]
    current.push_back(arr[index]);
    getCombinationsWithSumUtil(arr, index, target - arr[index], current, result);
    current.pop_back();
}

vector<vector<int>> getCombinationsWithSum(vector<int> arr, int target) {

    vector<int> current;
    vector<vector<int>> result;

    getCombinationsWithSumUtil(arr, 0, target, current, result);

    return result;
}

int main() {
    
    vector<vector<int>> result = getCombinationsWithSum({2, 4, 6, 8}, 8);

    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}