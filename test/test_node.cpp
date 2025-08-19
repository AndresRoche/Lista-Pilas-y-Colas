#include <iostream>
#include "lpc/Node.cpp"

using namespace std;

int main() {

    Node<int> gato(5);
    Node<int> gato_2(10, &gato);

    cout << gato_2.getVal() << endl;
    cout << (gato_2.getNext())->getVal() << endl;

    Node<int> h(100);
    Node<int> m(0);
    
    m.setVal(h.getVal() * 5);

    m.setNext(&h);
    h.setNext(&gato_2);

    cout << "m vale: " << m.getVal() << endl;

    cout << "h vale: " << m.getNext()->getVal() << endl;

    cout << "gato_2 vale : " << m.getNext()->getNext()->getVal() << endl;

    cout << "gato vale : " << m.getNext()->getNext()->getNext()->getVal() << endl;


}