#include <iostream>
#include "lpc/Stack.cpp"

int main() {

    std::cout << "Testing Stack Implementation\n\n" << std::endl;

    Stack<int> stack;

    stack.push(20);
    stack.push(50);
    stack.push(80);
    stack.push(100);


    std::cout << stack;

    std::cout << "Stack size: " << stack.getSize() << std::endl;

    std::cout << "Top element: " << stack.peek() << std::endl;

    std::cout << "Popping element: " << stack.pop() << std::endl;
    
    std::cout << "Stack after pop:" << std::endl;
    
    std::cout << stack;

    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "Clearing stack..." << std::endl;
    stack.clear();

    std::cout << "Is stack empty after clear? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
    
    std::cout << "\n\nend of test" << std::endl;

}