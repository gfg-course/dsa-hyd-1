#include <bits/stdc++.h>
using namespace std;


// TC: O(n)
// Auxiliary Space: O(1)
// SC: O(n)

int smallestPositiveMissingNumber(vector<int> arr) {
    int n = arr.size();

    // Step-1: convert all the elements outside [1, n] with n + 1.
    for (int i = 0; i < n; i++) {
        if (arr[i] < 1 || arr[i] > n) {
            arr[i] = n + 1;
        }
    }

    // Step-2: mark the buckets negative for the elements present in the array.
    for (int i = 0; i < n; i++) {
        if (abs(arr[i]) <= n) {
            int bucketIndex = abs(arr[i]) - 1;
            if (arr[bucketIndex] > 0) {
                arr[bucketIndex] *= -1;
            }
        }
    }

    // Step-3: find the first positive number in the array.
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            return i + 1;
        }
    }

    return n + 1;
}


int main() {
    cout << smallestPositiveMissingNumber({1, 2, 3, 4, 5}) << endl;
    cout << smallestPositiveMissingNumber({0, -10, 1, 3, -20}) << endl;
}