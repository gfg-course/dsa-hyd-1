#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(k)
vector<int> slidingWindowMaximum(vector<int> arr, int k) {
    // edge case 
    if (k == 1 || arr.size() == 1) {
        return arr;
    }

    vector<int> result;
    deque<int> dq; // Hold the Indices.

    int left = 0;
    int right = 1;

    dq.push_back(left);

    while (right < arr.size()) {
        while (!dq.empty() && arr[right] > arr[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(right);

        if (right - left + 1 == k) {
            result.push_back(arr[dq.front()]);

            if (dq.front() == left) {
                dq.pop_front();
            }
            left++;
        }
        right++;
    }

    return result;
}

int main() {

    vector<int> result = slidingWindowMaximum({1, 2, 3, 1, 4, 5, 2, 3, 6}, 3);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> result2 = slidingWindowMaximum({8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, 4);
    for (int i : result2) {
        cout << i << " ";
    }
    cout << endl;
}