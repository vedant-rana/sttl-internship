#include <iostream>
#include <vector>
using namespace std;
class PriorityQueue {
private:
    vector<pair<int, int>> heap;  
    
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent].first > heap[index].first) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }
    
    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild].first < heap[smallest].first) {
                smallest = leftChild;
            }

            if (rightChild < size && heap[rightChild].first < heap[smallest].first) {
                smallest = rightChild;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void push(int priority, int value) {
        heap.push_back({priority, value});
        heapifyUp(heap.size() - 1);
    }

    int top() {
        if (heap.empty()) {
            throw out_of_range("PriorityQueue is empty");
        }
        return heap[0].second;
    }

    void pop() {
        if (heap.empty()) {
            throw out_of_range("PriorityQueue is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    bool empty() const {
        return heap.empty();
    }

    size_t size() const {
        return heap.size();
    }
};

int main() {
    PriorityQueue pq;

    pq.push(3, 30);
    pq.push(1, 10);
    pq.push(2, 20);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
