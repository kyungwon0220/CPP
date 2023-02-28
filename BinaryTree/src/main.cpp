#include "이진트리순회연산.h"

int main() {
    Node* n7 = new Node(68);
    Node* n6 = new Node(67);
    Node* n5 = new Node(66);
    Node* n4 = new Node(65);
    Node* n3 = new Node('/', n6, n7);
    Node* n2 = new Node('*', n4, n5);
    Node* n1 = new Node('-', n2, n3);

    std::cout << "preorder :\t";
    n1->preorder(n1);
    std::cout << std::endl;

    std::cout << "inorder :\t";
    n1->inorder(n1);
    std::cout << std::endl;

    std::cout << "postorder :\t";
    n1->postorder(n1);
    std::cout << std::endl;
}
