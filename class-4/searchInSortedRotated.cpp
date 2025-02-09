#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int sortedRotatedSearch(vector<int> arr, int target) {
    
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        // Left half is sorted.
        if (arr[mid] >= arr[low]) {
            if (target >= arr[low] && target <= arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        else { // Right half is sorted.
            if (target >= arr[mid] && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    cout << sortedRotatedSearch({5, 6, 7, 8, 9, 10, 1, 2, 3}, 10) << endl;
    cout << sortedRotatedSearch({2, 3, 4, 5, 1}, 1) << endl;
    cout << sortedRotatedSearch({1, 2, 3, 4, 5}, 1) << endl;
}