#include "CircularQueue.h"

int main() {
    Queue q(5);

    q.enQueue(777);
    q.enQueue(666);
    q.enQueue(555);
    q.enQueue(444);
    q.enQueue(333);
    q.enQueue(222);
    q.printQ();

    std::cout << "pick : " << q.pickQ(2) << std::endl;

    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.printQ();
}
