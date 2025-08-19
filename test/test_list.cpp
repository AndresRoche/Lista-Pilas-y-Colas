#include <iostream>
#include "lpc/List.cpp"

int main() {
    List<int> myList;
    
    // Insert elements  
    myList.insertBack(10);
    myList.insertBack(20);
    myList.insertBack(30);
    myList.insertFront(5);
    myList.insert(15, 2); // Insert 15 at index 2
    myList.insert(25, 4); // Insert 25 at index 4
    myList.insert(15, 3); // Insert 35 at index 5
    myList.insertBack(15);
    myList.insertBack(15);

    std::cout << myList << std::endl;

    myList.removeFront(); // Remove front element
    myList.removeBack();  // Remove back element
    myList.removeByValue(15);
    myList.removeAll(15);

    std::cout << "After removals: " << myList << std::endl;

    myList.insertBack(15);
    myList.insertBack(15);
    myList.removeAll(15);
    std::cout << "After removing all 15s: " << myList << std::endl;

    // Test get methods
    try {
        std::cout << "Front: " << myList.getFront() << std::endl;
        std::cout << "Back: " << myList.getBack() << std::endl;
        std::cout << "Element at index 2: " << myList.getByIndex(2) << std::endl;
    } catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test operator[]
    try {
        std::cout << "Element at index 1 using operator[]: " << myList[1] << std::endl;
    } catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test swap
    try {
        myList.swap(0, 1);
        std::cout << "After swapping index 0 and 1: " << myList << std::endl;
    } catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }

    myList.insertFront(100);
    std::cout << myList << std::endl;

    myList.swap(4,0);

    myList.insertBack(200);
    myList.insertFront(300);

    std::cout << myList << std::endl;

    myList.reverse();

    std::cout << myList << std::endl;

    List<int> anotherList(myList);

    myList.extend(anotherList);

    std::cout << "After extending: " << myList << std::endl;

    myList.insertFront(400);
    myList.insertBack(500);
    std::cout << "After inserting 400 at front and 500 at back: " << myList << std::endl;
    std::cout << "List size: " << myList.getSize() << std::endl;

    // Test clear
    myList.clear();
    std::cout << "After clearing: " << myList << std::endl;

    // Check if list is empty
    std::cout << "Is list empty? " << (myList.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "List size: " << myList.getSize() << std::endl;
    
    for (int i = 1; i < 11; i++)
    {
        myList.insertBack(i*10);
    }
    std::cout << myList << std::endl; 
    myList[0] = 1000; // Change the first element to 1000
    std::cout << myList << std::endl;

    anotherList.copy(myList);
    std::cout << "Another list after copy: " << anotherList << std::endl;

    // Test equality operator
    if (myList == anotherList) {
        std::cout << "Both lists are equal." << std::endl;
    } else {
        std::cout << "Lists are not equal." << std::endl;
    }

    anotherList.insertBack(999); // Modify anotherList to make it different

    // Test inequality operator
    if (myList != anotherList) {
        std::cout << "Lists are not equal." << std::endl;
    } else {
        std::cout << "Both lists are equal." << std::endl;
    }



    myList.clear();
    anotherList.clear();



    List<std::string> stringList;
    stringList.insertBack("Hello");
    stringList.insertBack("World");
    stringList.insertFront("Greetings");

    std::cout << "String List: " << stringList << std::endl;

    stringList.clear();


    List<List<int> > superList;
    superList.insertBack(List<int>());
    superList[0].insertBack(1);
    superList[0].insertBack(2);
    superList[0].insertBack(3);

    superList.insertBack(List<int>());
    superList[1].insertBack(4);
    superList[1].insertBack(5);
    superList[1].insertBack(6);

    superList.insertBack(List<int>());
    superList[2].insertBack(7);
    superList[2].insertBack(8);
    superList[2].insertBack(9);

    std::cout << "Super List: " << superList << std::endl;

    std::cout << superList[0] << std::endl;
    std::cout << superList[1] << std::endl;
    std::cout << superList[2] << std::endl;


    for (int i = 0; i < 3; i++)
    {
        superList[i].clear();
    }
    
    superList.clear();
    std::cout << "Super List after clearing: " << superList << std::endl;

    return 0;
}