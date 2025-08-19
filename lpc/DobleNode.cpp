#include <iostream>
#ifndef LPC_DOBLENODE_CPP
#define LPC_DOBLENODE_CPP


template <typename T>
class DobleNode {
    protected:
        T val;
        DobleNode<T> * next;
        DobleNode<T> * prev;
        
    public:
        DobleNode(T val, DobleNode<T> * next = NULL, DobleNode<T> * prev = NULL) : val(val), next(next), prev(prev) {}

        inline T& getVal() { return val; }

        inline void setVal(T valor) { this->val = valor; }

        inline DobleNode<T>* getNext() { return next; }

        inline void setNext(DobleNode<T>* n) { this->next = n; }

        inline DobleNode<T>* getPrev() { return prev; }

        inline void setPrev(DobleNode<T>* p) { this->prev = p; }

        template <typename S>
        friend std::ostream& operator<<(std::ostream& os, const DobleNode<S>& node);
};


template <typename T>
std::ostream& operator<<(std::ostream& os, const DobleNode<T>& node) {

    if (node.prev) {
        os << node.prev->val << " <- Prev <-";
    } else {
        os << "NULL <- Prev <-";
    }
    os << "| " << node.val << " |";

    if (node.next) {
        os << "-> Next -> " << node.next->val;
    } else {
        os << "-> Next -> NULL";
    }
    
    return os;
}

#endif // LPC_DOBLENODE_CPP