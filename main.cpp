#include <iostream>
#include <sstream>
#include <string>
#include "lpc/List.cpp"
#include "lpc/Stack.cpp"
#include "lpc/Dqueue.cpp"

using namespace std;


int main() {


    List<int> list;
    Stack<char> stack;
    Dqueue<string> queue;


    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    cout << list << endl;

    stack.push('A');
    stack.push('B');
    stack.push('C');

    cout << stack << endl;

    queue.insertBack("Hello");
    queue.insertBack("World");
    queue.insertFront("Greetings");

    cout << queue << endl;

    return 0;
}

