#include <iostream>

class Node {
public:
    Node() : Node('\0') {}
    explicit Node(char key) : m_key(key), left(nullptr), right(nullptr) {}
    virtual ~Node() {}
    
    const Node* search(const char key) const;  // key값인 노드의 위치를탐색하는 연산
    const void inorder(const Node* root) const;  // 이진 탐색 트리를 중위 순회하면서 출력하는 연산

    Node* insert(Node* root, const char key) const;  // 포인터 root가 가리키는 노드와 비교하여 노드 key를 삽입하는 연산
    const void delNode(Node* root, const char key) const;  // 루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
    
private:
    char m_key;  // 데이터 필드
    Node* left;  // 왼쪽 서브 트리 링크 필드
    Node* right;  // 오른쪽 서브 트리 링크 필드
};
