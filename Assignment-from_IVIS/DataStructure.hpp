#include <iostream>
template <typename T> class List;

template <typename T>
class Node {
public:
    Node() :rlink(nullptr), llink(nullptr) {}
    virtual ~Node() {}
private:
    Node* rlink;
    Node* llink;
    T data;
    friend List<T>;
};

template <typename T>
class List {
private:
    Node<T>* head;
public:
    List() : head(nullptr) {}
    void creatList(const T& data);
    void printList() const;
    void pushBack(const T& data);
    void pushFront(const T& data);
    void popBack();
    void popFront();
    Node<T>* findNode(const T& data);
    void insertNode(Node<T>* pre, const T& data);
    void deleteNode(Node<T>* del);
    void clearList();
};




template <typename T>
void List<T>::creatList(const T& data) {
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    head = newNode;
}


template <typename T>
void List<T>::printList() const {
    Node<T>* tmp = head;

    while (tmp != nullptr) {
        std::cout << tmp->data << std:: endl;
        tmp = tmp->rlink;
    }
}

template <typename T>
void List<T>::pushBack(const T& data) {
    if (head == nullptr) {
        creatList(data);
    } else {
        Node<T>* tmp = head;
        Node<T>* newNode = new Node<T>;

        while (tmp != nullptr) {
            if (tmp->rlink == nullptr) {
                newNode->data = data;
                tmp->rlink = newNode;
                newNode->llink = tmp;
                break;
            }
            tmp = tmp->rlink;
        }       
    }
}


template <typename T>
void List<T>::pushFront(const T& data) {
    if (head == nullptr) {
        creatList(data);
    } else {
        Node<T>* newNode = new Node<T>;

        newNode->data = data;
        newNode->rlink = head;
        head = newNode;
    }
}

template <typename T>
void List<T>::popBack() {
    if (head == nullptr) {
        std::cout << "not found Target (head == nullptr" << std::endl;
    } else {
        Node<T>* tmp = head;

        while (tmp != nullptr) {
            if (tmp->rlink == nullptr) {
                tmp->llink->rlink = nullptr;
                delete tmp;
                tmp = nullptr;
                break;
            }
            tmp = tmp->rlink;
        }        
    }    
}

template <typename T>
void List<T>::popFront() {
    if (head == nullptr) {
        std::cout << "not found Target (head == nullptr" << std::endl;
    } else {
        Node<T>* tmp = head;

        head = tmp->rlink;

        delete tmp;
        tmp = nullptr;
    }
}

template <typename T>
Node<T>* List<T>::findNode(const T& data) {
    Node<T>* tmp = head;
    if (head == nullptr) {
        std::cout << "not found Target (head == nullptr" << std::endl;
    } else {
        while (tmp != nullptr) {
            if (tmp->data == data) {
                break;
            }
            
            tmp = tmp->rlink;
        }
    }

    return tmp;
}

template <typename T>
void List<T>::insertNode(Node<T>* pre, const T& data) {
    if (head == nullptr) {
        creatList(data);
    } else {
        Node<T>* newNode = new Node<T>;
        Node<T>* tmp = head;

        newNode->data = data;
        newNode->rlink = pre->rlink;
        newNode->llink = pre;
        pre->rlink = newNode;
    }
}

template <typename T>
void List<T>::deleteNode(Node<T>* del) {
    if (del == nullptr) {
        std::cout << "entered for ' nullptr ' (del == nullptr" << std::endl;
    } else if (head == nullptr) {
        std::cout << "not found Target (head == nullptr" << std::endl;
    } else {
        Node<T>* tmp = head;

        while (tmp != nullptr) {
            if (tmp == del) {
                if (del->rlink == nullptr) {
                    del->llink->rlink = nullptr;
                } else {
                    del->rlink->llink = del->llink;
                    if (del->llink == nullptr) {
                        head = del->rlink;                        
                    } else {
                        del->llink->rlink = del->rlink;                        
                    }
                }

                delete del;
                del = nullptr;
                break;
            }
            tmp = tmp->rlink;
        }
    }
}

template <typename T>
void List<T>::clearList() {
    if (head == nullptr) {
        std::cout << "not found Target (head == nullptr" << std::endl;
    } else {
        Node<T>* tmp = head;

        while (tmp != nullptr) {
            tmp = head->rlink;
            
            delete head;
            head = nullptr;
            
            head = tmp;
       }
    }    
}
