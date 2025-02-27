#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n)
 * AS: O(n)
*/
vector<int> productExceptSelf(vector<int> arr) {
    int n = arr.size();

    vector<int> suffProd(n);

    suffProd[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 1; i--) {
        suffProd[i] = suffProd[i + 1] * arr[i];
    }

    vector<int> ans(n);
    ans[0] = suffProd[1];
    int prefProd = arr[0];

    for (int i = 1; i < n - 1; i++) {
        ans[i] = prefProd * suffProd[i + 1];
        prefProd = prefProd * arr[i];
    }
    ans[n - 1] = prefProd;

    return ans;
}

int main() {
    vector<int> ans = productExceptSelf({1, 2, 3, 4});
    vector<int> ans2 = productExceptSelf({-1, 1, 0, -3, 3});

    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : ans2) {
        cout << i << " ";
    }
}