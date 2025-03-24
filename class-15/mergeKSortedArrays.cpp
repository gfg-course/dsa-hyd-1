#include <bits/stdc++.h>
using namespace std;

// TC: O(k^2 * log(k))
// AS: O(k)
vector<int> mergeKSortedArrays(vector<vector<int>> arr) {

    // {-value, {i, j}}
    priority_queue<pair<int, pair<int, int>>> pq;

    int k = arr.size();

    // O(k*log(k))
    for (int i = 0; i < k; i++) {
        pq.push({-arr[i][0], {i, 0}});
    }

    vector<int> result;

    // O(k^2 * log(k))
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        int value = -curr.first;
        int i = curr.second.first;
        int j = curr.second.second;

        result.push_back(value);
        if (j + 1 < arr[i].size()) {
            pq.push({-arr[i][j + 1], {i, j + 1}});
        }
    }

    return result;
}

int main() {

    vector<int> result = mergeKSortedArrays({{1, 5, 7, 10},
                                             {3, 4, 8, 9},
                                             {1, 2, 3, 4},
                                             {6, 11, 12, 13}});

    cout << result.size() << endl;
    for (int i : result) {
        cout << i << " ";
    }
}