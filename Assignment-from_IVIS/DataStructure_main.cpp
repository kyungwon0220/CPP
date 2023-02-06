#include "DataStructure.hpp"

int main() {
    List<std::string> newList;

    std::cout << "List Create Test" << std::endl;
    newList.creatList("wal");
    newList.printList();

    std::cout << std::endl << std::endl << "pushBack Test" << std::endl;
    newList.creatList("hwa");
    newList.pushBack("su");
    newList.pushBack("mok");
    newList.printList();
    
    std::cout << std::endl << "pushFront Test" << std::endl;
    newList.pushFront("gum");
    newList.printList();
    
    std::cout << std::endl << "popBack Test" << std::endl;
    newList.popBack();
    newList.pushBack("to");
    newList.printList();

    std::cout << std::endl << "popFront Test" << std::endl;
    newList.popFront();
    newList.pushBack("il");
    newList.printList();

    std::cout << std::endl << "find Test" << std::endl;
    newList.printList();
    Node<std::string>* p1 = newList.findNode("su");
    Node<std::string>* p2 = newList.findNode("hwa");
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    std::cout << std::endl << "insertNode Test" << std::endl;
    newList.insertNode(p1, "wall");
    newList.printList();

    std::cout << std::endl << "deleteNode Test" << std::endl;
    newList.deleteNode(p2);
    newList.printList();

    std::cout << std::endl << "clear Test" << std::endl;
    newList.clearList();
    newList.printList();
}
