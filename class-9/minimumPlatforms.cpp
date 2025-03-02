#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(n))
// AS: O(n)

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second == +1;
    }

    // if (a.first < b.first) {
    //     return true;
    // } else {
    //     return false;
    // }
    return a.first < b.first;
}

int minimumPlatforms(vector<int> arr, vector<int> dep) {
    int n = arr.size();

    vector<pair<int, int>> timeline;
    for (int i = 0; i < n; i++) {
        timeline.push_back({arr[i], +1});
        timeline.push_back({dep[i], -1});
    }

    sort(timeline.begin(), timeline.end(), comp);

    int currentPlatforms = 0, maxPlatforms = 0;
    for (int i = 0; i < timeline.size(); i++) {
        currentPlatforms += timeline[i].second;
        maxPlatforms = max(maxPlatforms, currentPlatforms);
    }

    return maxPlatforms;
}

int minimumPlatformsWithoutCustomComparator(vector<int> arr, vector<int> dep) {
    int n = arr.size();

    vector<pair<int, char>> timeline;
    for (int i = 0; i < n; i++) {
        timeline.push_back({arr[i], 'a'});
        timeline.push_back({dep[i], 'd'});
    }

    sort(timeline.begin(), timeline.end());

    int currentPlatforms = 0, maxPlatforms = 0;
    for (int i = 0; i < timeline.size(); i++) {
        currentPlatforms += timeline[i].second == 'a' ? +1 : -1;
        maxPlatforms = max(maxPlatforms, currentPlatforms);
    }

    return maxPlatforms;
}

int main() {
    cout << minimumPlatforms({900, 940, 950, 1100, 1500, 1800},
                             {910, 1200, 1120, 1130, 1900, 2000}) << endl;

    cout << minimumPlatformsWithoutCustomComparator({900, 940, 950, 1100, 1500, 1800},
                                                    {910, 1200, 1120, 1130, 1900, 2000}) << endl;


    cout << minimumPlatforms({900, 910},
                             {910, 1000}) << endl;

    cout << minimumPlatformsWithoutCustomComparator({900, 910},
                                                    {910, 1000}) << endl;    
}