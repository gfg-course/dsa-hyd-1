#include <bits/stdc++.h>
using namespace std;

/**
 * T(N) = 2*T(N/2) + N
 * 
 * AS: O(N) + O(log(N)) = O(N)
 * */


void merge(vector<int> &arr, int low, int mid, int high) {

    // Left half: arr[low ... mid]
    // Right half: arr[mid + 1 ... high]

    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while (left <= mid && right <= high) {
        if (arr[left] < arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[i + low] = temp[i];
    }
}

void mergeSortUtil(vector<int> &arr, int low, int high) {
    // Base case ??
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;
    mergeSortUtil(arr, low, mid);
    mergeSortUtil(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> arr) {

    return mergeSortUtil(arr, 0, arr.size() - 1);
}

int main() {
    
}