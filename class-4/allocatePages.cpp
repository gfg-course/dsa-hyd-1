#include <bits/stdc++.h>
using namespace std;

int getStudentsCount(vector<int> pages, int maxPages) {

    int numStudents = 1, pageCount = 0;
    for (int i = 0; i < pages.size(); i++) {
        if (pages[i] + pageCount <= maxPages) {
            pageCount += pages[i];
        } else {
            numStudents++;
            pageCount = pages[i];
        }
    }

    return numStudents;
}

// TC: O(n * log(sum))
// AS: O(1)
int allocatePages(vector<int> pages, int M) {

    int n = pages.size();
    if (M > n) { // If number of students is greater than the number of books.
        return -1;
    }

    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        low = max(low, pages[i]);
        high += pages[i];
    }

    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        int numOfStudents = getStudentsCount(pages, mid);
        if (numOfStudents <= M) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}


int main() {
    cout << allocatePages({12, 34, 67, 90}, 2) << endl;
    cout << allocatePages({10, 20, 10, 30}, 2) << endl;
    cout << allocatePages({10, 20, 10, 30}, 1) << endl;
    cout << allocatePages({10, 20, 10, 30}, 4) << endl;
    cout << allocatePages({10, 20, 10, 30}, 5) << endl;
}