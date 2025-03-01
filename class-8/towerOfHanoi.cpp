#include <bits/stdc++.h>
using namespace std;

/**
 * T(N) = 2*T(N - 1) + c if we want the entire steps.
 * T(N) = T(N - 1) + c if we just need the integer output.
 *
 * AS: O(N)
 * */

// Task is to move N disks from A to C using B.
int towerOfHanoi(int N, string A, string B, string C) {

    if (N == 0) {
        return N;
    }

    int result = towerOfHanoi(N - 1, A, C, B); // Move N - 1 disks from A to B.
    
    cout << "move disk " + to_string(N) + " from rod " << A << " to rod " << C << endl;
    result++; // Move the N-th disk from A to C.
    
    result += towerOfHanoi(N - 1, B, A, C); // Move N - 1 disks from B to C.

    return result;
}

int main() {
    
    cout << towerOfHanoi(3, "source", "aux", "target") << endl;
    // cout << towerOfHanoi(3) << endl;
}