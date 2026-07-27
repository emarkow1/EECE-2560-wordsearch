#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>


using namespace std;

template <typename T>
class Heap {
    public:
        Heap();
        
        int parent(const int& i) const;
        int left(const int& i) const;
        int right(const int& i) const;
        T getItem(const int& i) const;
        void initializeMaxHeap(const vector<T>& items);
        void maxHeapify(const int& i);
        void buildMaxHeap();
        vector<T> heapsort();


    private:
        vector<T> heap;
        int heapSize;
};


template <typename T>
Heap<T>::Heap() {
    
};

template <typename T>
int Heap<T>::parent(const int& i) const {
    return floor((i - 1) / 2);
};

template <typename T>
int Heap<T>::left(const int& i) const {
    return 2 * i + 1;
};

template <typename T>
int Heap<T>::right(const int& i) const {
    return 2 * i + 2;
};

template <typename T>
T Heap<T>::getItem(const int& i) const {
    return heap[i];
};

template <typename T>
void Heap<T>::initializeMaxHeap(const vector<T>& items) {
    heap = items;
    buildMaxHeap();
};

template <typename T>
void Heap<T>::maxHeapify(const int& i) {
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < heapSize && heap[l] > heap[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r < heapSize && heap[r] > heap[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(largest);
    }
};

template <typename T>
void Heap<T>::buildMaxHeap() {
    heapSize = heap.size();
    for (int i = floor(heap.size() / 2) - 1; i >= 0; i--) {
        maxHeapify(i);
    }
};

template <typename T>
vector<T> Heap<T>::heapsort() {
    buildMaxHeap();
    for (int i = heap.size() - 1; i >= 1; i--) {
        swap(heap[0], heap[i]);
        heapSize = heapSize - 1;
        maxHeapify(0);
    }
    return heap;
};

#endif
