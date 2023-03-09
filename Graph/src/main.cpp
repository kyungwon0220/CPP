#include "MyGraph.h"

int main() {
    // MyGraph* g1 = new MyGraph(100);

    // g1->insertV(0);
    // g1->insertV(1);
    // g1->insertV(2);
    // g1->insertV(3);
    
    // g1->insertEdge(0,3);
    // g1->insertEdge(0,1);
    // g1->insertEdge(1,3);
    // g1->insertEdge(1,2);
    // g1->insertEdge(1,0);
    // g1->insertEdge(2,3);
    // g1->insertEdge(2,1);
    // g1->insertEdge(3,2);
    // g1->insertEdge(3,1);
    // g1->insertEdge(3,0);
    // g1->printList();

    MyGraph* g2 = new MyGraph(10);

    g2->insertV(0);
    g2->insertV(1);
    g2->insertV(2);
    g2->insertV(2);

    g2->insertEdge(0, 2);
    g2->insertEdge(0, 1);
    g2->insertEdge(1, 2);
    g2->insertEdge(1, 0);
    g2->insertEdge(2, 1);
    g2->insertEdge(2, 0);
    g2->printList();
}
