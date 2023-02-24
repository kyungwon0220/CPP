#include "CircularQueue.h"

const bool Queue::isFull() const {
    bool tmp;

    if ((rear + 1)%m_qSize == front) {
        tmp = true;
    } else {
        tmp = false;
    }

    return tmp;
}

const bool Queue::isEmpty() const {
    bool tmp;

    if (front == rear) {
        tmp = true;
    } else {
        tmp = false;
    }

    return tmp;
}

const void Queue::enQueue(const size_t& data) {
    if (isFull()) {
        std::cout << "Circular Queue is Full!" << std::endl;
    } else {
        rear = (rear+1)%m_qSize;
        m_data[rear] = data;
    }
}

const size_t Queue::deQueue() {
    size_t tmp = m_data[front];

    m_data[front] = '\0';
    front = (front+1)%m_qSize;

    return tmp;
}

const void Queue::printQ() const {
    unsigned short f = (front+1)%m_qSize;
    unsigned short l = (rear+1)%m_qSize;
    unsigned short loop = f;

    while (loop != l) {
        std::cout << "now front : " << front << ", rear : " << rear << ", data : " << m_data[loop] << std::endl;
        loop = (loop+1)%m_qSize;
    }
    std::cout << std::endl;
}

const size_t Queue::pickQ(const unsigned short i) const {
    size_t tmp = '\0';

    if (isEmpty()) {
        std::cout << "Circular Queue is empty!" << std::endl;
    } else {
        tmp = m_data[i];
    }
    
    return tmp;
}
