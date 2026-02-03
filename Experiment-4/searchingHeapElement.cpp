#include <bits/stdc++.h>
using namespace std;

int heap[100];
int heapSize = 0;

bool searchElement(int key) {
    for (int i = 0; i < heapSize; i++) {
        if (heap[i] == key)
            return true;
    }
    return false;
}

void insertElement(int val) {
    heap[heapSize++] = val;
}

int main() {
    insertElement(10);
    insertElement(5);
    insertElement(20);
    insertElement(2);
    insertElement(8);

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    if (searchElement(key))
        cout << "Element found\n";
    else
        cout << "Element not found\n";

    return 0;
}
