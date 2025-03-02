#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<vector<int>> &arr) {
    
    return  i >= 0 && i < arr.size() &&
            j >= 0 && j < arr[i].size() &&
            arr[i][j] == 1;
}

int di[4] =  {+1, +0, +0, -1};
int dj[4] =  {+0, -1, +1, +0};
char dm[4] = {'D', 'L', 'R', 'U'};

/**
 * T(N) = 4 * T(N - 1) + c, where N = n*n (for n x n matrix).
 * AS: O(n * n) 
 * */

void ratInAMazeUtil(vector<vector<int>> &arr, int i, int j, string &current, vector<string> &result) {

    // Base case
    if (i == arr.size() - 1 && j == arr[i].size() - 1) {
        result.push_back(current);
        return;
    }

    arr[i][j] = 2;

    for (int k = 0; k < 4; k++) {
        int new_i = i + di[k];
        int new_j = j + dj[k];
        char dir = dm[k];

        if (isSafe(new_i, new_j, arr)) {
            current.push_back(dir);
            ratInAMazeUtil(arr, new_i, new_j, current, result);
            current.pop_back();
        }
    }

    arr[i][j] = 1;
}

vector<string> ratInAMaze(vector<vector<int>> arr) {

    vector<string> result;
    string current = "";

    int n = arr.size();
    int m = arr[0].size();

    ratInAMazeUtil(arr, 0, 0, current, result);

    return result;
}

int main() {
    vector<string> result = ratInAMaze({{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}});

    for (string s : result) {
        cout << s << endl;
    }

    vector<string> result2 = ratInAMaze({{1, 0}, {1, 0}});

    for (string s : result2) {
        cout << s << endl;
    }
}