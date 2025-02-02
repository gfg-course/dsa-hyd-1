#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(sqrt(n))
 * AS: O(1)
 * SC: O(1)
*/

// assume that n > 1
bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << isPrime(2) << endl;
    cout << isPrime(20) << endl;
    cout << isPrime(36) << endl;
    cout << isPrime(19) << endl;
}