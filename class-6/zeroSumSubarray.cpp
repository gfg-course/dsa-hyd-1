#include <bits/stdc++.h>
using namespace std;


// TODO-1: find the actual subarray.
// TODO-2: check if a subarray with sum = X is present or not.

/**
 * TC: O(n) 
 * AS: O(n)
*/
bool checkZeroSumSubarray(vector<int> arr) {
    
    int sum = 0;
    unordered_set<int> sumsOccurred;

    sumsOccurred.insert(0);

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // If the sum was seen before, return true.
        if (sumsOccurred.find(sum) != sumsOccurred.end()) {
            return true;
        }

        // Mark the current sum as seen, and move ahead.
        sumsOccurred.insert(sum);
    }

    return false;
}

int main() {
    cout << checkZeroSumSubarray({4, 2, -3, 1, 6}) << endl;
    cout << checkZeroSumSubarray({1, 2, -3, 4, 5}) << endl;
    cout << checkZeroSumSubarray({1, 2, 3, 4, 5}) << endl;
}