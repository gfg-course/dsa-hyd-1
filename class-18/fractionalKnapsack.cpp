#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(n))
// AS: O(n)
double maxValueInKnapsack(vector<int> vals, vector<int> wts, int capacity) {

    int n = vals.size();

    vector<pair<double, int>> valuePerWtToWt;

    for (int i = 0; i < n; i++) {
        valuePerWtToWt.push_back({vals[i] / (double)wts[i], wts[i]});
    }

    sort(valuePerWtToWt.begin(), valuePerWtToWt.end());

    double result = 0;
    for (int i = n - 1; i >= 0; i--) {
        
        double valuePerWt = valuePerWtToWt[i].first;
        int wt = valuePerWtToWt[i].second;

        // Whole of the current item can be accommodated
        if (capacity >= wt) {
            result += valuePerWt * wt;
            capacity -= wt;
        } else {
            // Break the item and cover the remaining space in the knapsack with this item.
            result += valuePerWt * capacity;
            capacity = 0;
            break;
        }
    }

    return result;
}

int main() {
    
    cout << maxValueInKnapsack({60, 100, 120}, {10, 20, 30}, 50) << endl;
}