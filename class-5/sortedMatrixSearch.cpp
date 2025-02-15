#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n + m)
 * AS: O(1)
*/
bool searchInSortedMatrix(vector<vector<int>> arr, int X) {
    int n = arr.size();
    int m = arr[0].size();

    int i = 0, j = m - 1;

    while (i < n && j >= 0) {
        if (arr[i][j] == X) {
            return true;
        }

        // Discard the column
        if (arr[i][j] > X) {
            j--;
        } else {
            i++;
        }
    }

    return false;
}

int main() {

    cout << searchInSortedMatrix({  {3, 30, 38},
                                    {36, 43, 60},
                                    {40, 51, 69},
                                    {41, 62, 70}}, 61) << endl;

    cout << searchInSortedMatrix({  {3, 30, 38},
                                    {36, 43, 60},
                                    {40, 51, 69},
                                    {41, 62, 70}}, 43) << endl;    

    cout << searchInSortedMatrix({  {3, 30, 38},
                                    {36, 43, 60},
                                    {40, 51, 69},
                                    {41, 62, 70}}, 41) << endl;    
}