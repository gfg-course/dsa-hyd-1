#include <bits/stdc++.h>
using namespace std;

// TODO: try to this iteratively to reduce the aux space to O(1).
void bottomUpHeapify(vector<int> &heap, int index) {
    if (index == 0) {
        return;
    }

    int parentIndex = (index - 1) / 2;
    if (heap[index] > heap[parentIndex]) {
        swap(heap[index], heap[parentIndex]);
        bottomUpHeapify(heap, parentIndex);
    }
}

void insertIntoHeap(vector<int> &heap, int value) {
    heap.push_back(value);

    // Heapify the last element!
    bottomUpHeapify(heap, heap.size() - 1);
}

void topDownHeapify(vector<int> &heap, int index) {

    int leftChildIndex = 2*index + 1;    
    int rightChildIndex = 2*index + 2;

    // index, leftChildIndex, rightChildIndex - get the max
    int maxValueIndex = index;
    if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[maxValueIndex]) {
        maxValueIndex = leftChildIndex;
    }
    if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[maxValueIndex]) {
        maxValueIndex = rightChildIndex;
    }

    if (maxValueIndex != index) {
        swap(heap[index], heap[maxValueIndex]);
        topDownHeapify(heap, maxValueIndex);
    }
}

void deleteFromHeap(vector<int> &heap) {
    
    int n = heap.size();
    if (n == 0) {
        return;
    }

    swap(heap[0], heap[n - 1]);
    heap.pop_back();

    topDownHeapify(heap, 0);
}

int main() {

    vector<int> heap = {100, 50, 80, 25, 40, 70, 10, 9, 20, 30};
    insertIntoHeap(heap, 60);

    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    deleteFromHeap(heap);
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;
}