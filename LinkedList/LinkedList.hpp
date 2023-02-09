#include <iostream>
template <typename T> class LinkedList;

template <typename T>
class LinkedNode {
public:
    LinkedNode() : next(nullptr) {}
private:
    LinkedNode* next;
    T data;
    friend LinkedList<T>;
};


template <typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    const void createList(const T& data);
    const void printList() const;
    const void pushBack(const T& data);
    const void pushFront(const T& data);
    const LinkedNode<T>* findNode(const T& data) const;
    const void insertNode(const LinkedNode<T>* pre, const T& data);
    const void deleteNode(const LinkedNode<T>* del);
    const void freeList();
    const void popBack() const;
    const void popFront();
private:
    LinkedNode<T>* head;
};


template <typename T>
const void LinkedList<T>::createList(const T& data) {
    LinkedNode<T>* newNode = new LinkedNode<T>;
    newNode->data = data;
    head = newNode;
}

template <typename T>
const void LinkedList<T>::printList() const {
    LinkedNode<T>* horse = head;

    while (horse != nullptr) {
        std::cout << horse->data << std:: endl;
        horse = horse->next;
    }
}

template <typename T>
const void LinkedList<T>::pushBack(const T& data) {
    if (head == nullptr) {
        createList(data);
    } else {
        LinkedNode<T>* horse = head;
        LinkedNode<T>* newNode = new LinkedNode<T>;

        while (horse != nullptr) {
            if (horse->next == nullptr) {
                newNode->data = data;
                horse->next = newNode;
                break;
            }
            horse = horse->next;
        } // while end
    }
}

template <typename T>
const void LinkedList<T>::pushFront(const T& data) {
    if (head ==nullptr) {
        createList(data);
    } else {
        LinkedNode<T>* newNode = new LinkedNode<T>;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
const LinkedNode<T>* LinkedList<T>::findNode(const T& data) const {
    LinkedNode<T>* temp = head;

    if (head == nullptr) {
        // std::cout << "not data. (head == nullptr)" << std::endl;
        temp = nullptr;
    } else {
        while (temp != nullptr) {
            if (temp->data == data) {
                break;
            }
            temp = temp->next;
        } // while end        
    }

    return temp;
}

template <typename T>
const void LinkedList<T>::insertNode(const LinkedNode<T>* pre, const T& data) {
    if (pre == nullptr) {
        createList(data);
    } else {
        LinkedNode<T>* horse = head;
        LinkedNode<T>* newNode = new LinkedNode<T>;

        while (horse != nullptr) {
            if (horse == pre) {
                newNode->data = data;
                newNode->next = horse->next;
                horse->next = newNode;
                break;
            }
            horse = horse->next;
        } // while end
    }
}

template <typename T>
const void LinkedList<T>::deleteNode(const LinkedNode<T>* del) {
    if (del == nullptr) {
        std::cout << "not data. (pre == nullptr)" << std::endl;
    } else if (del->next == nullptr) {
        popBack();       
    } else if (del == head)  {
        head = del->next;

        delete del;
        del = nullptr;
    } else {
        LinkedNode<T>* temp = head;

        while (temp != nullptr) {
            if (temp->next == del) {
                temp->next = del->next;

                delete del;
                del = nullptr;

                break;
            }
            temp = temp->next;
        } // while end
    }
}

template <typename T>
const void LinkedList<T>::freeList() {
    if (head == nullptr) {
        std::cout << "failed. (list alredy NULL)" << std::endl;
    } else {
        LinkedNode<T>* temp;

        while (temp != nullptr) {
            temp = head->next;
            delete head;
            head = nullptr;
            head = temp;
        }
    }
}

template <typename T>
const void LinkedList<T>::popBack() const {
    if (head == nullptr) {
        std::cout << "failed. (list alredy NULL)" << std::endl;
    } else {
        LinkedNode<T>* temp = head;

        while (temp != nullptr) {
            if (temp->next->next == nullptr) {
                delete temp->next;
                temp->next = nullptr;
                break;
            }
            temp = temp->next;
        }
    }    
}

template <typename T>
const void LinkedList<T>::popFront() {
    if (head == nullptr) {
        std::cout << "failed. (list alredy NULL)" << std::endl;
    } else {
        LinkedNode<T>* temp = head->next;
        
        delete head;
        head = temp;
    }    
}
