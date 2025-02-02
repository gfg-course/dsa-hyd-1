
/**
 * TC: O(n + m)
 * AS: O(1)
 * SC: O(n + m)
*/


for (int i = 0; i < A.size(); i++) { // n
    cout << A[i] << endl;
}
for (int i = 0; i < B.size(); i++) { // m
    cout << B[i] << endl;
}

// ---------------------------------------------------

/**
 * TC: O(n * m)
 * AS: O(1)
 * SC: O(n + m)
 * 
*/
for (int i = 0; i < A.size(); i++) { // n
    for (int j = 0; j < B.size(); j++) { // m
        cout << A[i] + B[j] << endl;
    }
}

// ---------------------------------------------------

/**
 * TC: O(n^2)
 * AS: O(1)
 * SC: O(1)
*/

void func(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << i + j << endl;
        }
    }
}

// ---------------------------------------------------

/**
 * TC: O(m*n^2)
 * AS: O(1)
 * SC: O(m)
*/

// s.length() == `m`
void func(int n, string s) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << s << endl;
        }
    }
}

