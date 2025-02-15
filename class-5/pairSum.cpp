#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n)
 * AS: O(1)
*/
bool pairSum(vector<int> arr, int target) {
    int n = arr.size();

    int left = 0, right = n - 1;
    while (left < right) {

        if (arr[left] + arr[right] == target) {
            return true;
        }

        if (arr[left] + arr[right] > target) {
            right--;
        } else {
            left++;
        }
    }

    return false;
}

int main() {  
    
    cout << pairSum({1, 2, 5, 6, 10}, 8) << endl;
    cout << pairSum({1, 2, 5, 6, 10}, 20) << endl;
    cout << pairSum({1, 2, 5, 6, 10, 10}, 20) << endl;
}