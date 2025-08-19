#include <iostream>
#ifndef LPC_NODE_CPP
#define LPC_NODE_CPP

template <typename T>
class Node
{
    private:
        T val;
        Node<T> * next;

    public:
        Node(T val, Node<T> * next = NULL ) : val(val), next(next) {}

        inline T& getVal() { return val; }

        inline void setVal (T valor)  {this->val = valor;}

        inline Node<T> * getNext ()  {return next;}

        inline void setNext(Node<T> * n)  { this->next = n;}

};


#endif
