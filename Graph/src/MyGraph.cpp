#include "MyGraph.h"
#include <iostream>

const void MyGraph::insertV(const unsigned short v) {
    if (v > m_maxVertex + 1) {
        std::cout << "ERR : 그래프 정점의 개수를 초과하였습니다!" << std::endl;
    } else if (v < n) {
        std::cout << "ERR : 이미 있는 정점이므로 삽입 불가" << std::endl;
    } else {
        ++n;
    }
}

const void MyGraph::insertEdge(unsigned short v1, const unsigned short v2) const {
    if (v1 >= n || v2 >= n) {
        std::cout << "ERR : 그래프에 없는 정점입니다!" << std::endl;
    } else {
        Node* newNode = new Node;
        
        newNode->vertex = v2;
        newNode->link = adjList[v1].link;
        adjList[v1].link = newNode;
    }
}

const void MyGraph::printList() const {
    for (unsigned short i = 0; i < n; ++i) {
        Node* horse = (adjMatrix+i)->link;  // 최초 헤드의 vertex == '\0' 이므로, 헤드 노드의 link 노드부터 출력
        
        std::cout << "정점 " << (char)(i + 'A') << " 의 인접 리스트";  // 인덱스 숫자인 정점을, 알파벳으로 출력

        while (horse != nullptr) {
            std::cout << " -> " << (char)((horse->vertex) + 'A');
            horse = horse->link;
        }
        std::cout << std::endl;
    }
}
