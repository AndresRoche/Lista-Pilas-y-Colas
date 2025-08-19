#include <iostream>
#include "lpc/Dqueue.cpp"

int main() {

    Dqueue<int> queue;
    queue.insertBack(10);
    queue.insertBack(20);
    queue.insertBack(30);
    queue.insertBack(40);
    queue.insertBack(50);
    queue.insertBack(60);
    std::cout << queue << std::endl;

    std::cout << "Front: " << queue.getFront() << std::endl;
    std::cout << "Back: " << queue.getBack() << std::endl;

    std::cout << "Deleting front: " << queue.deleteFront() << std::endl;
    std::cout << "After deleting front: " << queue << std::endl;

    std::cout << "Deleting back: " << queue.deleteBack() << std::endl;
    std::cout << "After deleting back: " << queue << std::endl;

    queue.insertFront(5);
    queue.insertFront(1);
    std::cout << queue << std::endl;

    std::cout << "Queue is empty: " << queue.isEmpty() << std::endl;
    std::cout << "Queue size: " << queue.getSize() << std::endl;

    std::cout << "Clearing queue..." << std::endl;
    queue.clear();

    std::cout << queue << std::endl;

    queue.insertBack(100);
    queue.insertFront(50);
    queue.insertBack(150);
    std::cout << queue << std::endl;
    return 0;
}