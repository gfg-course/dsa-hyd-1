#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(log(n))
 * AS: O(log(n))
 * SC: O(log(n))
*/
// TODO: try to solve it iteratively.
int countDigits(int n) {
    if (n / 10 == 0) {
        return 1;
    }
    return 1 + countDigits(n / 10);
}

int sumDigits1ToN(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += countDigits(i);
    }
    return result;
}

int main() {
    cout << countDigits(10) << endl;
    cout << countDigits(0) << endl;
    cout << countDigits(9) << endl;
    cout << countDigits(1234313) << endl;

    cout << sumDigits1ToN(10) << endl;
    cout << sumDigits1ToN(25) << endl;
}