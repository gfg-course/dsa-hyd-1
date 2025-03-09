#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<int> nextGreaterElements(vector<int> arr) {

    int n = arr.size();
    stack<int> helper;

    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!helper.empty() && helper.top() <= arr[i]) {
            helper.pop();
        }

        if (helper.empty()) {
            result[i] = -1;
        } else {
            result[i] = helper.top();
        }

        helper.push(arr[i]);
    }

    return result;
}

int main() { 

    vector<int> res = nextGreaterElements({6, 8, 0, 1, 3});
    vector<int> res2 = nextGreaterElements({8, 1, 3, 2});

    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : res2) {
        cout << i << " ";
    }
    cout << endl;
}