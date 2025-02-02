#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n*log(log(n)))
 * AS: O(n)
 * SC: O(n)
*/

vector<int> getAllPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> result;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            result.push_back(i);
            for (int j = i*i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return result;
}

int main() {
    vector<int> result = getAllPrimes(20);
    for (int i : result) {
        cout << i << " ";
    }
}