#include "MyHeap.h"

template class Heap<unsigned short>;  // 템플릿 자료형, 명시적 선언

template<typename T>
void Heap<T>::insert(T item) {
    if (heapSize >= m_maxSize) {
        std::cout << "Heap is FULL" << std::endl;
    } else {
        unsigned short i = ++heapSize;

        while ((i > 1) && (heap[i/2] < item)) {
            heap[i] = heap[i/2];
            i /= 2;
        }
        heap[i] = item;
    }
}

template<typename T>
T Heap<T>::popDelete() {
    if (heapSize < 1) {
        throw std::out_of_range("ERR: Heap is NULL");
    } else {
        T answer = heap[1];
        T tmp = heap[heapSize];            
        unsigned short parent = 1;
        unsigned short child = 2;
        
        heap[heapSize--] = '\0';
        
        while (child <= heapSize) {
            if (heap[child] < heap[child+1]) {
                child++;
            }

            if (tmp > heap[child]) {
                break;
            } else {
                heap[parent] = heap[child];
                parent = child;
                child *= 2;
            }
            
        }

        heap[parent] = tmp;

        return answer;
    }
}

template<typename T>
void Heap<T>::print() {
    if (heapSize < 1) {
        std::cout << "Heap is NULL" << std::endl;
    } else {
        std::cout << "\nHeap Max : " << m_maxSize << "\nHeap Size : " << heapSize << std::endl;
        for (unsigned short i = 1; i <= heapSize; ++i) {
            std::cout << "HEAP[" << i << "] : " << heap[i] << std::endl;
        }
    }
}
