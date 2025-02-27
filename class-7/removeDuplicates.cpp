#include <bits/stdc++.h>
using namespace std;


/**
 * TC: O(n)
 * AS: O(1)
 * */

int removeDuplicates(vector<int> &arr) {
    int n = arr.size();
    
    int i = 1, j = 1;
    while (j < n) {
        // move j such that it becomes the first occurrence of element it points to.
        while (j < n && arr[j] == arr[j - 1]) {
            j++;
        }

        arr[i] = arr[j];
        i++;
        j++;
    }

    return i;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 2, 3, 3, 4};
    int size = removeDuplicates(arr);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    vector<int> arr2 = {1, 1, 2, 2, 2, 2, 3, 3, 4};
    int size2 = removeDuplicates(arr2);

    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }

    cout << endl;

    vector<int> arr3 = {1, 2, 3, 4};
    int size3 = removeDuplicates(arr3);

    for (int i = 0; i < size3; i++) {
        cout << arr3[i] << " ";
    }
}