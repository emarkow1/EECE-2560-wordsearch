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


#endif
