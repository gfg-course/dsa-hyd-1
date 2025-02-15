#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n + maxx)
 * AS: O(maxx)
 * 
 * where maxx is the max of all (L[i], R[i])
*/

int maxInNRanges(vector<int> L, vector<int> R) {
    int n = L.size();

    int maxx = 0;
    for (int i = 0; i < n; i++) {
        maxx = max({maxx, L[i], R[i]});
    }

    vector<int> freq(maxx + 2, 0);

    for (int i = 0; i < n; i++) {
        freq[L[i]]++;
        freq[R[i] + 1]--;
    }

    int maxFreqIndex = 0;
    // Convert to pref-sum so that freq[i] represents the frequency of element `i`.
    for (int i = 1; i <= maxx + 1; i++) {
        freq[i] = freq[i] + freq[i - 1];
        if (freq[i] > freq[maxFreqIndex]) {
            maxFreqIndex = i;
        }
    }

    return maxFreqIndex;
}

int main() {  

    cout << maxInNRanges({1, 4, 3, 1, 19}, {15, 8, 5, 4, 20});
}