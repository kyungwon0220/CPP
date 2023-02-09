#include "LinkedList.hpp"

int main() {
    std::cout << std:: endl << std::endl << "create Test =====" << std::endl;
    LinkedList<std::string> list1;
    list1.createList("test가즈아");
    list1.printList();


    std::cout << std:: endl << std::endl << "push Test =====" << std::endl;
    LinkedList<std::string> list2;
    list1.pushBack("test2");
    list2.pushBack("test3");
    list1.pushBack("test4");
    std::cout << std::endl << "list1:" << std::endl;
    list1.printList();
    std::cout << std::endl << "list2:" << std::endl;
    list2.printList();
    list2.pushFront("test8");
    list1.pushFront("test9");
    std::cout << std::endl << "list2:" << std::endl;
    list2.printList();
    std::cout << std::endl << "list1:" << std::endl;
    list1.printList();


    std::cout << std:: endl << std::endl << "insert Test =====" << std::endl;
    list1.insertNode(list1.findNode("test2"), "test5");
    list1.insertNode(list1.findNode("test2"), "test6");
    std::cout << std::endl << "list1:" << std::endl;
    list1.printList();

    LinkedList<std::string> list3;
    list3.insertNode(nullptr, "test7");
    std::cout << std::endl << "list3:" << std::endl;
    list3.printList();
    list3.findNode("test1");

    list3.freeList();
    std::cout << std::endl << "list3:" << std::endl;
    list3.printList();


    std::cout << std:: endl << std::endl << "delete Test =====" << std::endl;
    list2.deleteNode(nullptr);
    list2.deleteNode(list2.findNode("test3"));
    std::cout << std::endl << "list2:" << std::endl;
    list2.printList();
    list3.deleteNode(list3.findNode("test7"));
    std::cout << std::endl << "list3:" << std::endl;
    list3.printList();




    std::cout << std:: endl << std::endl << "pop Test =====" << std::endl;
    list1.popBack();
    std::cout << std::endl << "list1:" << std::endl;
    list1.printList();
    list1.popBack();
    std::cout << std::endl << "list1:" << std::endl;
    list1.printList();
    list3.popBack();
    list3.popFront();
    list1.popFront();
    list1.popFront();
    std::cout << std::endl << "list1:" << std::endl;
    list1.printList();
}
