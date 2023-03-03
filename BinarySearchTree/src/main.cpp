#include "BinarySearchTree.h"

int main() {
    Node* root = new Node('G');
    root->insert(root, 'I');
    root->insert(root, 'H');
    root->insert(root, 'D');
    root->insert(root, 'B');
    root->insert(root, 'M');
    root->insert(root, 'N');
    root->insert(root, 'A');
    root->insert(root, 'J');
    root->insert(root, 'E');
    root->insert(root, 'Q');
    root->inorder(root);    
    root->insert(root, 'C');
    root->insert(root, 'F');
    root->insert(root, 'K');
    root->insert(root, 'L');
    root->insert(root, 'O');
    root->insert(root, 'P');

    std::cout << std::endl;
    root->inorder(root);
    root->insert(root, 'Q');

    root->delNode(root, 'P');
    std::cout << std::endl;
    root->inorder(root);
    
    root->delNode(root, 'P');
    std::cout << std::endl;
    root->inorder(root);
}
