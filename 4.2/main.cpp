#include <iostream>
#include <vector>
using namespace std;


class MaxHeap {
private:
    vector<int> heap;

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if (left < heap.size() && heap[left] > heap[index]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            throw "Heap is empty";
        }
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return max;
    }

    void increase(int index, int value) {
        if (index < 0 || index >= heap.size()) {
            throw "Invalid index";
        }
        heap[index] += value;
        heapifyUp(index);
    }
};

int main() {
    MaxHeap maxHeap;
    string command;
    while (cin >> command) {
        if (command == "enqueue") {
            int k;
            cin >> k;
            maxHeap.insert(k);
        } else if (command == "dequeue_max") {
            try {
                cout << maxHeap.extractMax() << endl;
            } catch (const char* msg) {
                cout << "*" << endl;
            }
        } else if (command == "inc") {
            unsigned int i;
            int v;
            cin >> i >> v;
            try {
                maxHeap.increase(i-1, v);
            } catch (const char* msg) {
                cerr << "Error: " << msg << endl;
            }
        }
    }
    return 0;
}