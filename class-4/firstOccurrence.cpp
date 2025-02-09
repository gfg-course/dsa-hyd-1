#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int firstOccurrence(vector<int> arr, int target) {
    int low = 0, high = arr.size() - 1;

    int firstOccurrence = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        // Update the firstOccurrence & continue searching in the left half.
        if (arr[mid] == target) {
            firstOccurrence = mid;
            high = mid - 1;
        } else if (target > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return firstOccurrence;
}

int main() {

    cout << firstOccurrence({1, 5, 5, 5, 5, 5, 67, 123, 125}, 5) << endl;
    cout << firstOccurrence({1, 5, 5, 5, 5, 5, 67, 123, 125}, 67) << endl;
    cout << firstOccurrence({1, 5, 5, 5, 5, 5, 67, 123, 125}, 2) << endl;
}