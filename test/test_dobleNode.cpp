#include <iostream>
#include "lpc/DobleNode.cpp"

int main() {
    DobleNode<int> node1(10);
    DobleNode<int> node2(20, &node1);
    DobleNode<int> node3(30, &node2, &node1);
    
    std::cout << "Node 1: " << node1 << std::endl;
    std::cout << "Node 2: " << node2 << std::endl;
    std::cout << "Node 3: " << node3 << std::endl;

    node1.setNext(&node2);
    node1.setPrev(&node3);
    node2.setPrev(&node3);

    std::cout << "After linking:" << std::endl;
    std::cout << "Node 1: " << node1 << std::endl;
    std::cout << "Node 2: " << node2 << std::endl;
    std::cout << "Node 3: " << node3 << std::endl;

    std::cout << "Node 2 Value: " << node2.getVal() << std::endl;
    node2.setVal(25);
    std::cout << "Node 2 New Value: " << node2.getVal() << std::endl;

    return 0;

}