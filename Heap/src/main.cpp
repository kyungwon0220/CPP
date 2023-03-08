#include "MyHeap.h"

int main() {
    Heap<unsigned short> heap(100);

    heap.insert(10);
    heap.insert(45);
    heap.insert(19);
    heap.insert(11);
    heap.insert(96);
    heap.print();

    std::cout << heap.popDelete() << std::endl;
    heap.print();
    heap.insert(100);
    heap.print();

    for (unsigned short i = 0; i < 5; ++i) {
        std::cout << heap.popDelete() << std::endl;
        heap.print();
    }
}