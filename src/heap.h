// EECE 2560 Wordsearch Project
// 1-satbermacmar-2b
// heap.h
// authors: Jake Berman, Ethan Markow, Donald Mackinnon, Emile Sater
// This file declares and implements the Heap class as a template class.



#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T>
class Heap
// template Heap class (of type T) that stores T objects in a vector. in this
// class the member functions enablet the creation of a max heap and can sort
// elements using it.
{
    public:

        // empty heap object constructed
        Heap();
        
        // returns index of parent of index i item
        int parent(const int& i) const;

        // returns index of left child of index i item
        int left(const int& i) const;

        // returns index of right child of index i item
        int right(const int& i) const;

        // returns a COPY of index i item in heap
        T getItem(const int& i) const;

        // puts items into the heap vector and creates a max heap out of them
        void initializeMaxHeap(const vector<T>& items);

        // at index i, will restore the max heap
        void maxHeapify(const int& i);

        // builds/turns the heap vector into a max heap
        void buildMaxHeap();

        // sorts items in ascending order with heapsort. returns sorted vector
        vector<T> heapsort();


    private:
        vector<T> heap;
        int heapSize;
};


template <typename T>
Heap<T>::Heap()
// constructs empty Heap object
{
};

template <typename T>
int Heap<T>::parent(const int& i) const
// returns index of the parent of index i
{
    return floor((i - 1) / 2);
};

template <typename T>
int Heap<T>::left(const int& i) const
// returns index of the left child of index i
{
    return 2 * i + 1;
};

template <typename T>
int Heap<T>::right(const int& i) const
// returns index of the right child of index i
{
    return 2 * i + 2;
};

template <typename T>
T Heap<T>::getItem(const int& i) const
// returns copy of index i (from heap vector)
{
    return heap[i];
};

template <typename T>
void Heap<T>::initializeMaxHeap(const vector<T>& items)
// copies "items" into a heap vector and buids a max heap using it.
{
    heap = items;
    buildMaxHeap();
};

template <typename T>
void Heap<T>::maxHeapify(const int& i)
// ensures that all the properties for a max heap are met at index i subtree
{

    // indexes of left and right children
    int l = left(i);
    int r = right(i);
    int largest;

    // determine if left is larger than parent
    if (l < heapSize && heap[l] > heap[i]) {
        largest = l;
    } else {
        largest = i;
    }

    // determine if right is larger than whats currentyl largest
    if (r < heapSize && heap[r] > heap[largest]) {
        largest = r;
    }

    // if the parent is not the largest (e.g. a child is largest), swap the
    // largest with parent. continue the maxheapify with new positions.
    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(largest);
    }
};

template <typename T>
void Heap<T>::buildMaxHeap()
// rearranges the items in a vector to ensure they are a max heap
{
    heapSize = heap.size();

    // begins at the non-leaf nodes (nodes with children) and applies
    // maxheapify to each parent going forward towards the root.
    for (int i = floor(heap.size() / 2) - 1; i >= 0; i--)
    {
        maxHeapify(i);
    }
};

template <typename T>
vector<T> Heap<T>::heapsort()
// sorts heap vector (ascending) using heapsort
{

    // ensures that vector is a max heap
    buildMaxHeap();

    // continuously moves the largest root item to the end of the vector
    for (int i = heap.size() - 1; i >= 1; i--)
    {
        swap(heap[0], heap[i]);
        heapSize = heapSize - 1;
        maxHeapify(0);
    }
    return heap;
};

#endif // HEAP_H
