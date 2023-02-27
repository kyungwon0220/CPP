#include <iostream>

class Queue {
public:
    explicit Queue(size_t qSize) : m_qSize(qSize) { m_data = new size_t[m_qSize + 1]; }
    virtual ~Queue() { delete m_data; }

    const bool isFull() const;
    const bool isEmpty() const;
    const void enQueue(const size_t& data);
    const size_t deQueue();
    const void printQ() const;
    const size_t pickQ(const unsigned short i) const;
private:
    size_t m_qSize;
    size_t* m_data;

    unsigned short front = 0;
    unsigned short rear = 0;
};
