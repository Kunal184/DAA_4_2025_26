#include <bits/stdc++.h>
using namespace std;

int heap[100];
int heapSize = 0;

void deleteElement(int key) {
    int index = -1;

    for (int i = 0; i < heapSize; i++) {
        if (heap[i] == key) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Element not found\n";
        return;
    }

    heap[index] = heap[heapSize - 1];
    heapSize--;

    heapifyDown(index);
    heapifyUp(index);
}

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

void insertElement(int val) {
    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
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

    cout << "Heap before deletion: ";
    printHeap();

    int key;
    cout << "Enter element to delete: ";
    cin >> key;

    deleteElement(key);

    cout << "Heap after deletion: ";
    printHeap();

    return 0;
}
