#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)

// TODO: extend this to find till the first decimal place.
int sqrt(int n) {
    int low = 1, high = n;
    int result = 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid * mid == n) {
            return mid;
        }
        if (mid * mid > n) {
            high = mid - 1;
        } else {
            result = mid;
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    cout << sqrt(5) << endl;
    cout << sqrt(10) << endl;
    cout << sqrt(20) << endl;
    cout << sqrt(36) << endl;
}