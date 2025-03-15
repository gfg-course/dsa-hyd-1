#include <bits/stdc++.h>
using namespace std;

// TC: O(N)
// AS: O(N*Log(N))
vector<string> generate1ToN(int n) {

    vector<string> result;
    queue<string> q;
    q.push("1");

    int i = 0;
    while (i < n) {

        string curr = q.front();
        q.pop();

        result.push_back(curr);

        // TODO: opimize the number of pushes so that
        // we do not push more than N elements into the queue.
        q.push(curr + "0");
        q.push(curr + "1");

        i++;
    }

    return result;
}

int main() { 

    vector<string> result = generate1ToN(10);
    for (string i : result) {
        cout << i << endl;
    }
}