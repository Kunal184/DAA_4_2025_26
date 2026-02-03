#include <bits/stdc++.h>
using namespace std;

int heap[100];     
int heapSize = 0;  

void heapifyUp(int index) {
    if (index == 0) return;

    int parent = (index - 1) / 2;
    if (heap[index] < heap[parent]) {
        swap(heap[index], heap[parent]);
        heapifyUp(parent);
    }
}

void heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;

    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void insertElement(int value) {
    heap[heapSize] = value;
    heapSize++;
    heapifyUp(heapSize - 1);
}

void deleteRoot() {
    if (heapSize == 0) {
        cout << "Heap is empty\n";
        return;
    }

    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
}

void printHeap() {
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    insertElement(10);
    insertElement(5);
    insertElement(20);
    insertElement(2);
    insertElement(8);

    cout << "Min Heap: ";
    printHeap();

    deleteRoot();
    cout << "After deleting root: ";
    printHeap();

    return 0;
}
