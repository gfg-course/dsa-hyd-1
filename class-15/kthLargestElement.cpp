#include <bits/stdc++.h>
using namespace std;

// TC: O(n*log(k))
// AS: O(k)

int kthLargest(vector<int> arr, int k) {
    
    int n = arr.size();

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // k*log(k)
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // (n-k)*log(k)
    for (int i = k; i < n; i++) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int kthLargestAlternate(vector<int> arr, int k) {
    
    int n = arr.size();

    // Max-heap
    priority_queue<int> pq;

    // k*log(k)
    for (int i = 0; i < k; i++) {
        pq.push(-arr[i]);
    }

    // (n-k)*log(k)
    for (int i = k; i < n; i++) {
        if (arr[i] > -pq.top()) {
            pq.pop();
            pq.push(-arr[i]);
        }
    }

    return -pq.top();
}

int main() {

    cout << kthLargest({3, 5, 4, 2, 9}, 3) << endl;
    cout << kthLargestAlternate({3, 5, 4, 2, 9}, 3) << endl;
}