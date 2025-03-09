#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(vector<int> arr) {

    int n = arr.size();
    stack<int> helper;

    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!helper.empty() && arr[helper.top()] >= arr[i]) {
            helper.pop();
        }

        if (helper.empty()) {
            result[i] = n;
        } else {
            result[i] = helper.top();
        }

        helper.push(i);
    }

    return result;
}

vector<int> prevSmallerElements(vector<int> arr) {

    int n = arr.size();
    stack<int> helper;

    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        while (!helper.empty() && arr[helper.top()] >= arr[i]) {
            helper.pop();
        }

        if (helper.empty()) {
            result[i] = -1;
        } else {
            result[i] = helper.top();
        }

        helper.push(i);
    }

    return result;
}

// TC: O(n)
// AS: O(n)
int maxAreaHistogram(vector<int> bars) {
    int n = bars.size();

    vector<int> prevSmaller = prevSmallerElements(bars);
    vector<int> nextSmaller = nextSmallerElements(bars);

    int result = 0;
    for (int i = 0; i < n; i++) {
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        int height = bars[i];

        result = max(result, width * height);
    }

    return result;
}

int main() { 

    cout << maxAreaHistogram({6, 2, 5, 4, 5, 1, 6}) << endl;
}