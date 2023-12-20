#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct HeapNode
{
    int value;
    size_t operation;

    HeapNode(int v, size_t op) : value(v), operation(op) {}

    bool operator<(const HeapNode &other) const
    {
        return value < other.value || (value == other.value && operation > other.operation);
    }
};

class PriorityQueue
{
private:
    vector<HeapNode> heap;
    size_t operationCount = 0;

    void heapifyUp(size_t idx)
    {
        while (idx > 0)
        {
            size_t parent = (idx - 1) / 2;
            if (heap[idx] < heap[parent])
                break;
            swap(heap[idx], heap[parent]);
            idx = parent;
        }
    }

    void heapifyDown(size_t idx)
    {
        size_t size = heap.size();
        while (2 * idx + 1 < size)
        {
            size_t left = 2 * idx + 1;
            size_t right = 2 * idx + 2;
            size_t j = left;
            if (right < size && heap[right] < heap[left])
            {
                j = right;
            }
            if (heap[idx] < heap[j])
                break;
            swap(heap[idx], heap[j]);
            idx = j;
        }
    }

public:
    void enqueue(int value)
    {
        operationCount++;
        heap.push_back(HeapNode(value, operationCount));
        heapifyUp(heap.size() - 1);
    }

    void dequeue_max()
    {
        if (heap.empty())
        {
            cout << "*" << endl;
            return;
        }
        cout << heap[0].operation << " " << heap[0].value << endl;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
        {
            heapifyDown(0);
        }
    }

    void increase(size_t operation, int value)
    {
        for (auto &node : heap)
        {
            if (node.operation == operation)
            {
                node.value += value;
                heapifyUp(&node - &heap[0]);
                break;
            }
        }
    }
};

int main()
{
    PriorityQueue pq;
    string command;
    while (cin >> command)
    {
        if (command == "enqueue")
        {
            int k;
            cin >> k;
            pq.enqueue(k);
        }
        else if (command == "dequeue_max")
        {
            pq.dequeue_max();
        }
        else if (command == "inc")
        {
            size_t i;
            int v;
            cin >> i >> v;
            pq.increase(i, v);
        }
    }
    return 0;
}