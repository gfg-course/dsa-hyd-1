#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int majorityElement(vector<int> arr) {

    int count = 0, candidate = -1;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            count = 1;
            candidate = arr[i];
        } else if (arr[i] != candidate) {
            count--;
        } else {
            count++;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > n/2) {
        return candidate;
    }
    return -1;
}

int main() {
    cout << majorityElement({1, 2, 3, 2, 3, 3, 3}) << endl;
    cout << majorityElement({1, 2, 3, 2, 3, 3}) << endl;
}