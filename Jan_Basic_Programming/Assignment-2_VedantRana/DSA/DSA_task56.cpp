#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DoubleEndedPriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (2 * index + 1 < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int minChild = leftChild;

            if (rightChild < size && heap[rightChild] < heap[leftChild]) {
                minChild = rightChild;
            }

            if (heap[index] > heap[minChild]) {
                swap(heap[index], heap[minChild]);
                index = minChild;
            } else {
                break;
            }
        }
    }

public:
    void pushFront(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pushBack(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int popFront() {
        if (heap.empty()) {
            cerr << "Error: DoubleEndedPriorityQueue is empty." << endl;
            exit(1);
        }

        int frontValue = heap[0];
        swap(heap[0], heap.back());
        heap.pop_back();
        heapifyDown(0);
        return frontValue;
    }

    int popBack() {
        if (heap.empty()) {
            cerr << "Error: DoubleEndedPriorityQueue is empty." << endl;
            exit(1);
        }

        int backValue = heap.back();
        heap.pop_back();
        return backValue;
    }

    bool empty() const {
        return heap.empty();
    }
};

int main() {
    DoubleEndedPriorityQueue deq;

 
    deq.pushFront(5);
    deq.pushBack(3);
    deq.pushFront(7);

    cout << "Front element: " << deq.popFront() << endl;
    cout << "Back element: " << deq.popBack() << endl;

    return 0;
}
