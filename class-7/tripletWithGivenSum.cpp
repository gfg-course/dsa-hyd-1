#include <bits/stdc++.h>
using namespace std;

// -------------- UTIL FUNCTIONS START --------------

/**
 * TC: O(n)
 * AS: O(n)
 * */
bool pairWithGivenSumUsingHashMap(vector<int> arr, int start, int end, int target) {

    unordered_set<int> set;
    for (int i = start; i <= end; i++) {
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
bool pairWithGivenSumUsingTwoPointer(vector<int> arr, int start, int end, int target) {

    int n = arr.size();
    int i = start, j = end;
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

// -------------- UTIL FUNCTIONS END --------------

/**
 * TC: O(n^2)
 * AS: O(n)
 * */
bool tripletWithGivenSumUsingHashMap(vector<int> arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n - 2; i++) {
        if (pairWithGivenSumUsingHashMap(arr, i + 1, n - 1, target - arr[i]))  {
            return true;
        }
    }
    return false;
}

bool tripletWithGivenSumUsingTwoPointer(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 0; i < n - 2; i++) {
        if (pairWithGivenSumUsingTwoPointer(arr, i + 1, n - 1, target - arr[i])) {
            return true;
        }
    }

    return false;
}


int main() {
    cout << tripletWithGivenSumUsingHashMap({1, 4, 45, 6, 10, 8}, 13) << endl;
    cout << tripletWithGivenSumUsingHashMap({1, 4, 45, 6, 10, 8}, 30) << endl;

    cout << tripletWithGivenSumUsingTwoPointer({1, 4, 45, 6, 10, 8}, 13) << endl;
    cout << tripletWithGivenSumUsingTwoPointer({1, 4, 45, 6, 10, 8}, 30) << endl;
}