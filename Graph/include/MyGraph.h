class Node {  // 인접 리스트의 노드 구조
public:
    Node() : vertex('\0'), link(nullptr) {}
private:
    unsigned short vertex;
    Node* link;
    friend class MyGraph;
};

class MyGraph {  // 인접 리스트로 표현하는 그래프
public:
    MyGraph() : MyGraph(2) {}
    explicit MyGraph(const unsigned short maxVertex) : m_maxVertex(maxVertex) {}

    const void insertV(const unsigned short v);  // 그래프에 정점을 삽입하는 연산
    const void insertEdge(const unsigned short v1, const unsigned short v2) const;  // 그래프에 간선(v1,v2)를 삽입하는 연산
    const void printList() const;  // 그래프의 각 정점에대한 인접 리스트를 출력하는 연산
private:
    unsigned short n = 0;  // 그래프의 정점 개수
    unsigned short m_maxVertex;  // 헤드 포인터 배열의 최대 크기
    Node* adjMatrix = new Node[m_maxVertex];  // 그래프 정점에 대한 헤드 포인터 배열
};
