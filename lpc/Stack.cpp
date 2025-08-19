#include <iostream>
#include "Node.cpp"

#ifndef LPC_STACK_CPP
#define LPC_STACK_CPP

template <typename T>
class Stack {
    private:
        int size;
        Node<T> * top;

    public:
        Stack() ; 

        Stack(const Stack<T>& other); 

        ~Stack(); 
        
        void push(const T& value); 

        T pop(); 

        T peek()  ;

        inline bool isEmpty()    ;

        inline int getSize()    ;

        void clear(); 
    
        template <typename S>
        friend std::ostream& operator<<(std::ostream& os, const Stack<S>& stack);
};

template <typename T>
Stack<T>::Stack() : size(0), top(NULL)  {};

template <typename T>
Stack<T>::Stack( const Stack<T>& other) : top(NULL),  size(other.size)
{
    if (other.top == NULL) {
        this->top = NULL;
        return;
    }

    // Copiar el primer nodo
    this->top = new Node<T>(other.top->getVal());
    Node<T> * currentOther = other.top->getNext();
    Node<T> * currentThis = this->top;

    // Copiar los nodos restantes
    while (currentOther != NULL) {
        currentThis->setNext(new Node<T>(currentOther->getVal()));
        currentThis = currentThis->getNext();
        currentOther = currentOther->getNext();
    }
}

template <typename T>
void Stack<T>::push(const T& value)
{
    Node<T> * nodo = new Node<T>(value, this->top);
    this->top = nodo;
    this->size++;
}


template <typename T>
T Stack<T>::pop()
{
    if (this->top == NULL) {
        throw std::out_of_range("Stack is empty");
    }
    Node<T> * nodo = this->top;
    T value = nodo->getVal();
    this->top = nodo->getNext();
    delete nodo;
    this->size--;
    return value;
} 

template <typename T>
T Stack<T>::peek() 
{
    if (this->top == NULL) {
        throw std::out_of_range("Stack is empty");
    }
    return this->top->getVal();
}

template <typename T>
bool Stack<T>::isEmpty() 
{
    return this->top == NULL;
}

template <typename T>
int Stack<T>::getSize() 
{
    return this->size;
}

template <typename T>
void Stack<T>::clear() 
{
    while (this->top != NULL) {
        this->pop();
    }
}


template <typename T>
Stack<T>::~Stack() 
{
    this->clear();
}


template <typename S>
std::ostream& operator<<(std::ostream& os, const Stack<S>& stack)
{
    if (stack.top == NULL){
        os << "Stack is empty\n";
        return os;
    }

    Node<S> * current = stack.top;
    os << "Stack:[ ";
    while(current!=NULL)
    {
        os << current->getVal() << " ";
        current = current->getNext();
    }

    os << "]";
    
    return os;
}

#endif // LPC_STACK_CPP