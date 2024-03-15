#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template<typename T>
class DoubleEndedPriorityQueue {
private:
    std::vector<T> maxHeap;  
    std::vector<T> minHeap; 

public:
    void insertFront(const T& value) {
        maxHeap.push_back(value);
        std::push_heap(maxHeap.begin(), maxHeap.end());
        balanceHeaps();
    }

    void insertBack(const T& value) {
        minHeap.push_back(value);
        std::push_heap(minHeap.begin(), minHeap.end(), std::greater<T>());
        balanceHeaps();
    }

    T deleteFront() {
        if (maxHeap.empty() && minHeap.empty()) {
            throw std::out_of_range("DoubleEndedPriorityQueue is empty");
        }

        T result;

        if (!maxHeap.empty()) {
            std::pop_heap(maxHeap.begin(), maxHeap.end());
            result = maxHeap.back();
            maxHeap.pop_back();
        } else {
            result = minHeap.front();
            std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<T>());
            minHeap.pop_back();
        }

        balanceHeaps();
        return result;
    }

    T deleteBack() {
        if (maxHeap.empty() && minHeap.empty()) {
            throw std::out_of_range("DoubleEndedPriorityQueue is empty");
        }

        T result;

        if (!minHeap.empty()) {
            std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<T>());
            result = minHeap.back();
            minHeap.pop_back();
        } else {
            result = maxHeap.front();
            std::pop_heap(maxHeap.begin(), maxHeap.end());
            maxHeap.pop_back();
        }

        balanceHeaps();
        return result;
    }

    void balanceHeaps() {
        if (maxHeap.size() > minHeap.size() + 1) {
            T maxFront = deleteFront();
            minHeap.push_back(maxFront);
            std::push_heap(minHeap.begin(), minHeap.end(), std::greater<T>());
        } else if (minHeap.size() > maxHeap.size()) {
            T minFront = deleteBack();
            maxHeap.push_back(minFront);
            std::push_heap(maxHeap.begin(), maxHeap.end());
        }
    }

    bool isEmpty() const {
        return maxHeap.empty() && minHeap.empty();
    }
};

int main() {
    DoubleEndedPriorityQueue<int> depq;

    depq.insertFront(5);
    depq.insertBack(10);
    depq.insertFront(3);
    depq.insertBack(8);

    while (!depq.isEmpty()) {
        std::cout << "Front: " << depq.deleteFront() << ", Back: " << depq.deleteBack() << std::endl;
    }

    return 0;
}
