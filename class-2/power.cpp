#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(log(b))
 * AS: O(log(b))
 * SC: O(log(b))
*/

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }

    int temp = power(a, b/2);

    // if b is even, return temp * temp
    if (b % 2 == 0) {
        return temp * temp;
    }

    // if b is odd, return a * temp * temp
    return a * temp * temp;
}

int main() {
    cout << power(2, 3) << endl;
    cout << power(5, 2) << endl;
    cout << power(7653, 0) << endl;
    cout << power(7653, 1) << endl;
    cout << power(2, 10) << endl;
    cout << power(0, 10) << endl;
}