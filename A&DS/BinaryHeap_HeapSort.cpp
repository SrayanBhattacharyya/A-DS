#include <bits/stdc++.h>
using namespace std;

/*
* MinHeap - Parent <= Children (Root is minimum element)
* MaxHeap - Parent >= Children (Root is maximum element)
* Code is for MinHeap
*/

vector <int> heap, a;

void ShiftUp (int i) {
    while (i > 0 && (heap[i] < heap[(i - 1) / 2])) {           
        swap (heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void ShiftDown () {
    int i = 0, n = heap.size();
    while (2 * i + 1 < n) { //Atleast 1 child
        int j = 2 * i + 1;
        if ((2 * i + 2 < n) && heap[j + 1] < heap[j]) j = 2 * i + 2; // If right child exists and is smaller than left child
        if (heap[j] >= heap[i]) break;  // Maxheap condition already satisfied
        swap (heap[i], heap[j]);
        i = j;
    }
}

void insert (int x) {
    heap.emplace_back(x);
    int n = heap.size();
    // Shift Up Operation
    ShiftUp(n - 1);
}

int remove_min () {
    int n = heap.size();
    swap (heap[0], heap[n - 1]); // h[0] (min. element) swapped with last element;
    int ret = heap[n - 1];
    heap.pop_back();
    ShiftDown();
    return ret;
}

void HeapSort(vector <int> &a) {
    for (auto &x : a) insert(x);
    for (int i = 0; i < a.size(); i++) a[i] = remove_min();
}

