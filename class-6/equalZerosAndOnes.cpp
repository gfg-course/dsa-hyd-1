#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n)
 * AS: O(n)
 */ 
long long int countSubarraysWithEqual0sAnd1s(vector<int> arr) { // containing only 0s and 1s.

    int sum = 0;
    unordered_map<int, int> sumFreq;
    sumFreq[0] = 1;

    long long int result = 0;
    for (int i = 0; i < arr.size(); i++) {
        // sum += arr[i] == 1 ? 1 : -1;
        if (arr[i] == 1) {
            sum += 1;
        } else {
            sum -= 1;
        }

        result += sumFreq[sum];
        sumFreq[sum]++;
    }

    return result;
}

int main() {
    cout << countSubarraysWithEqual0sAnd1s({1, 0, 0, 1, 0, 1, 1}) << endl;
    cout << countSubarraysWithEqual0sAnd1s({1, 1, 1, 1, 0}) << endl;
}