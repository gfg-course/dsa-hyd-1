#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n)
 * AS: O(n)
 * */
bool pairWithGivenSumUsingHashMap(vector<int> arr, int target) {

    int n = arr.size();
    unordered_set<int> set;
    for (int i = 0; i < n; i++) {
        if (set.find(target - arr[i]) != set.end()) {
            return true;
        }
        set.insert(arr[i]);
    }
    return false;
}

/**
 * TC: O(n)
 * AS: O(1)
 * */
bool pairWithGivenSumUsingTwoPointer(vector<int> arr, int target) {

    int n = arr.size();
    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] == target) {
            return true;
        }
        if (target > arr[i] + arr[j]) {
            i++;
        } else {
            j--;
        }
    }
    return false;
}

int main() {
    cout << pairWithGivenSumUsingHashMap({1, 5, 2, 6, 10}, 8) << endl;
    cout << pairWithGivenSumUsingHashMap({1, 5, 2, 6, 10}, 9) << endl;

    cout << pairWithGivenSumUsingTwoPointer({1, 2, 5, 6, 10}, 8) << endl;
    cout << pairWithGivenSumUsingTwoPointer({1, 2, 5, 6, 10}, 9) << endl;
}