#include <iostream>
#include <vector>

using namespace std;

class MaxHeapPriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int maxIndex = index;
        int leftC = leftChild(index);
        int rightC = rightChild(index);

        if (leftC < heap.size() && heap[leftC] > heap[maxIndex]) {
            maxIndex = leftC;
        }

        if (rightC < heap.size() && heap[rightC] > heap[maxIndex]) {
            maxIndex = rightC;
        }

        if (index != maxIndex) {
            swap(heap[index], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            cout << "Priority queue is empty.\n";
            return;
        }

        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (heap.empty()) {
            cout << "Priority queue is empty.\n";
            return -1; 
        }
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

private:
    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }
};

int main() {
    MaxHeapPriorityQueue pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    cout << "Top element: " << pq.top() << "\n";

    pq.pop();

    cout << "Top element after pop: " << pq.top() << "\n";

    return 0;
}
