#include "BinarySearchTree.h"

const void Node::inorder(const Node* root) const {  // 이진 탐색 트리를 중위 순회하면서 출력하는 연산
    if (root) {
        inorder(root->left);
        if (root->m_key != '\0') {
            std::cout << root->m_key << "_";
        }        
        inorder(root->right);
    }
}

Node* Node::insert(Node* root, const char key) const {  // 포인터 root가 가리키는 노드와 비교하여 노드 key를 삽입하는 연산
    Node* tmp = root;

    if (tmp == nullptr) {
        Node* newNode = new Node(key);

        tmp = newNode;
    } else if (key < tmp->m_key) {
        tmp->left = insert(tmp->left, key);
    } else if (key > tmp->m_key) {
        tmp->right = insert(tmp->right, key);
    } else {
        std::cout << std::endl << "이미 같은 키가 있습니다!" << std::endl;
    }

    return tmp;
}

const void Node::delNode(Node* root, const char key) const {  // 루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
    Node* horse = root;
    Node* parent = nullptr;  // 삭제할 key를 가진 노드의, 부모 노드

    while ((horse != nullptr) && (horse->m_key != key)) {
        parent = horse;
        
        if ((horse->m_key < key) && (horse != nullptr)) {
            horse = horse->right;
        } else if ((horse->m_key > key) && (horse != nullptr)) {
            horse = horse->left;
        }
    }
    
    if (horse == nullptr) {  // 삭제할 노드가 없는 경우
        std::cout << std::endl << "찾는 키가 이진 트리에 없습니다!" << std::endl;
    } else if ((horse->left == nullptr) && (horse->right == nullptr)) {  // 삭제할 노드가 단말 노드인 경우
        if (parent == nullptr) {  // 삭제할 노드에 부모 노드까지 없으면, 삭제하는 노드가 이진 탐색 트리의 하나뿐인 노드이므로
            root->m_key = '\0';
        } else {
            if (parent->left == horse) {
                parent->left = nullptr;
            } else if (parent->right == horse) {
                parent->right = nullptr;
            }
        }
    } else if ((horse->left == nullptr) || (horse->right == nullptr)) {  // 삭제할 노드가 자식 노드를 한 개 가진 경우
        Node* child;

        if (horse->left != nullptr) {
            child = horse->left;
        } else if (horse->right != nullptr) {
            child = horse->right;
        }

        if (parent == nullptr) {
            root = child;
        } else {
            if (parent->left == horse) {
                parent->left = child;
            } else if (parent->right == horse) {
                parent->right = child;
            }
        }
    } else {  // 삭제할 노드가 자식 노드를 두 개 가진 경우
        Node*succ_parent = horse;
        Node*succ = horse->left;

        while (succ->right != nullptr) {  // 왼쪽 서브 트리에서 후계자 찾기
            succ_parent = succ;
            succ = succ->right;
        }

        if (succ_parent->left == succ) {
            succ_parent->left = succ->left;
        } else if (succ_parent->right == succ) {
            succ_parent->right = succ->left;
        }

        horse->m_key = succ->m_key;
        horse = succ;
    }

    delete horse;
    horse = nullptr;
}
