#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n)
 * AS: O(1)
*/
int removeDuplicatesAndReturnSize(vector<int> &arr) {

    int n = arr.size();
    int i = 0, j = 0;
    while (j < n) {
        arr[i] = arr[j];
        i++;

        // Move j to the beginning of the next array under consideration.
        j++;
        while (j < n and arr[j] == arr[j - 1]) {
            j++;
        }
    }

    return i;
}

int main() {  

    vector<int> arr = {1, 1, 2, 2, 2, 3, 3, 4, 4, 4};
    int n = removeDuplicatesAndReturnSize(arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}