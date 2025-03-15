#include <bits/stdc++.h>
using namespace std;

// TC: O(N)
// AS: O(N)
void reverseQueueUtil(queue<int> &q) {
    if (q.empty()) {
        return;
    }

    int elem = q.front();
    q.pop();
    reverseQueueUtil(q);

    q.push(elem);
}

queue<int> reverseQueue(queue<int> q) {

    reverseQueueUtil(q);
    return q;    
}


int main() { 
}