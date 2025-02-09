#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int binarySearch(vector<int> arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (target > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {

    cout << binarySearch({1, 2, 3, 4, 7, 99, 100}, 1) << endl;
    cout << binarySearch({1, 2, 3, 4, 7, 99, 100}, 2) << endl;
    cout << binarySearch({1, 2, 3, 4, 7, 99, 100}, 3) << endl;
    cout << binarySearch({1, 2, 3, 4, 7, 99, 100}, 4) << endl;
    cout << binarySearch({1, 2, 3, 4, 7, 99, 100}, 7) << endl;
    cout << binarySearch({1, 2, 3, 4, 7, 99, 100}, 99) << endl;
    cout << binarySearch({1, 2, 3, 4, 7, 99, 100}, 100) << endl;
    cout << binarySearch({1, 2, 3, 4, 7, 99, 100}, 5) << endl;
}