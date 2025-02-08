#include <bits/stdc++.h>
using namespace std;


// TC: O(n * m)
// AS: O(n + m)
void booleanMatrix(vector<vector<int>> &arr) {

    int n = arr.size();
    int m = arr[0].size();

    vector<bool> rowZero(m, false);
    vector<bool> colZero(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                rowZero[i] = true;
                colZero[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rowZero[i] || colZero[j]) {
                arr[i][j] = 0;
            }
        }
    }
}


// TC: O(n * m)
// AS: O(1)
void booleanMatrixBucketing(vector<vector<int>> &arr) {

    int n = arr.size();
    int m = arr[0].size();
    

    bool setTopRowZero = false;
    bool setLeftColZero = false;

    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            setLeftColZero = true;
            break;
        }
    }

    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 0) {
            setTopRowZero = true;
            break;
        }
    }

    // Mark the row & col buckets for all the 0s present in the matrix.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0; // row bucket
                arr[0][j] = 0; // col bucket
            }
        }
    }

    // Mark the elements 0 looking at the corresponding row & col buckets.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    if (setTopRowZero) {
        for (int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }
    if (setLeftColZero) {
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> arr = { {1, 0, 1, 0},
                                {1, 1, 1, 1},
                                {0, 1, 1, 1}};

    booleanMatrixBucketing(arr);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}