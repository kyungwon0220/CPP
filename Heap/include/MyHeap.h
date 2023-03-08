#include <iostream>

template <typename T>
class Heap {
public:
    Heap() : Heap(1) {}
    explicit Heap(unsigned short maxSize) : m_maxSize(maxSize), heapSize(0) {}    

    void insert(T item);
    T popDelete();
    void print();
    
private:
    unsigned short m_maxSize;
    T* heap = new T[m_maxSize];
    unsigned short heapSize;
};