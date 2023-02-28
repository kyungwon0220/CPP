#include <iostream>

class Node {
public:
    Node() : Node('\0') {}
    explicit Node(const char data, Node* left = nullptr, Node* right = nullptr) : m_data(data), m_left(left), m_right(right) {}
    virtual ~Node() {}

    const void preorder(const Node* root) const;
    const void inorder(const Node* root) const;
    const void postorder(const Node* root) const;
private:
    char m_data;
    Node* m_left;
    Node* m_right;
};
