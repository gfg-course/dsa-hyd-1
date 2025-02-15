#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n)
 * AS: O(n)
*/
vector<int> productOfArrayExceptSelf(vector<int> arr) {
    int n = arr.size();

    vector<int> prefProd(n);
    vector<int> suffProd(n);

    prefProd[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefProd[i] = prefProd[i - 1] * arr[i];
    }

    suffProd[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffProd[i] = suffProd[i + 1] * arr[i];
    }

    vector<int> result(n);
    result[0] = suffProd[1];
    result[n - 1] = prefProd[n - 2];

    for (int i = 1; i < n - 1; i++) {
        result[i] = prefProd[i - 1] * suffProd[i + 1];
    }

    return result;
}


/**
 * TC: O(n)
 * AS: O(n)
*/
// TODO: try to solve using prefProd[] & not suffProd[]
vector<int> productOfArrayExceptSelfSpaceOptimized(vector<int> arr) {
    int n = arr.size();

    vector<int> suffProd(n);

    suffProd[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffProd[i] = suffProd[i + 1] * arr[i];
    }

    vector<int> result(n);
    int prefProd = arr[0];
    result[0] = suffProd[1];

    for (int i = 1; i < n - 1; i++) {
        result[i] = prefProd * suffProd[i + 1];
        prefProd = prefProd * arr[i];
    }

    result[n - 1] = prefProd;

    return result;
}


int main() {  

    vector<int> result1 = productOfArrayExceptSelfSpaceOptimized({1, 2, 3, 4});
    vector<int> result2 = productOfArrayExceptSelfSpaceOptimized({1, 2, 0, 4});
    vector<int> result3 = productOfArrayExceptSelfSpaceOptimized({0, 2, 0, 4});

    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < result3.size(); i++) {
        cout << result3[i] << " ";
    }
    cout << endl;

}