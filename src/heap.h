#ifndef HEAP_H
#define HEAP_H
#include <vector>

using namespace std;

template <typename T>
class Heap {
    public:
        Heap();
        
        T parent(const int& i) const;
        T left(const int& i) const;
        T right(const int& i) const;
        T getItem(const int& i) const;
        void initalizeMaxHeap(const vector<T>& items);
        void maxHeapify();
        void buildMaxHeap();
        vector<T> heapsort();


    private:
        vector<T> heap;
};


#endif
