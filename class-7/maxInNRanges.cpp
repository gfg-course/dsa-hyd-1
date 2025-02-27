#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n + maxx)
 * AS: O(maxx)
 *  where maxx is the maximum element in R[]
 * */
int maxInNRanges(vector<int> L, vector<int> R) {
    int n = L.size();

    int maxx = 0;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx, R[i]);
    }

    vector<int> freq(maxx + 2, 0);
    for (int i = 0; i < n; i++) {
        freq[L[i]]++;
        freq[R[i] + 1]--;
    }

    // Do a prefix sum so that freq[] denotes the frequencies of the elements.
    for (int i = 1; i <= maxx + 1; i++) {
        freq[i] = freq[i] + freq[i - 1];
    }

    // result is the index with the maximum value in freq[].
    int result = 0;
    for (int i = 1; i <= maxx + 1; i++) {
        if (freq[i] > freq[result]) {
            result = i;
        }
    }

    return result;
}

int main() {
    cout << maxInNRanges({2, 1, 3}, {5, 3, 9}) << endl;
    cout << maxInNRanges({1, 4, 3, 1}, {15, 8, 5, 4}) << endl;
}