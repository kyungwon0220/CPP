#include "이진트리순회연산.h"

const void Node::preorder(const Node* root) const {  // 이진 트리에 대한 전위 순회 연산
    if (root) {
        std::cout << root->m_data;  // 작업 D : 현재 노드를 방문하여 처리한다.
        preorder(root->m_left);  // 작업 L : 현재 노드의 왼쪽 서브 트리로 이동한다.
        preorder(root->m_right);  // 작업 R : 현재 노드의 오른쪽 서브 트리로 이동한다.
    }
}

const void Node::inorder(const Node* root) const {  // 이진 트리에 대한 중위 순회 연산
    if (root) {
        inorder(root->m_left);  // 작업 L : 현재 노드의 왼쪽 서브 트리로 이동한다.
        std::cout << root->m_data;  // 작업 D : 현재 노드를 방문하여 처리한다.
        inorder(root->m_right);  // 작업 R : 현재 노드의 오른쪽 서브 트리로 이동한다.
    }
}

const void Node::postorder(const Node* root) const {  // 이진 트리에 대한 후위 순회 연산
    if (root) {
        postorder(root->m_left);  // 작업 L : 현재 노드의 왼쪽 서브 트리로 이동한다.
        postorder(root->m_right);  // 작업 R : 현재 노드의 오른쪽 서브 트리로 이동한다.
        std::cout << root->m_data;  // 작업 D : 현재 노드를 방문하여 처리한다.
    }
}
