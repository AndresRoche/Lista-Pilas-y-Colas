#include <iostream>
#include "DobleNode.cpp"

#ifndef LPC_DQUEUE_CPP
#define LPC_DQUEUE_CPP

template <typename T>
class Dqueue {
    protected:
        DobleNode<T> * front;
        DobleNode<T> * back;
        int size;
        
    public:
        Dqueue() : front(NULL), back(NULL), size(0) {}
        Dqueue(const Dqueue<T>& other);
        ~Dqueue() ;
        
        void insertFront(const T& val);
        void insertBack(const T& val);
        T deleteFront();
        T deleteBack();
        T getFront();
        T getBack();
        bool isEmpty() const { return size == 0; }
        int getSize() const { return size; }
        void clear();

        template <typename S>
        friend std::ostream& operator<<(std::ostream& os, const Dqueue<S>& queue);
};

template <typename T>
Dqueue<T>::Dqueue(const Dqueue<T>& other) : front(NULL), back(NULL), size(other.size) {

    if(other.front == NULL) {
        return;
    }

    this->front = new DobleNode<T>(other.front->getVal());
    DobleNode<T>* currentOther = other.front->getNext();
    DobleNode<T>* currentThis = this->front;

    while (currentOther != NULL) {
        currentThis->setNext(new DobleNode<T>(currentOther->getVal()));
        currentThis->getNext()->setPrev(currentThis);

        // Move to the next node
        currentThis = currentThis->getNext();
        currentOther = currentOther->getNext();
    }

    this->back = currentThis;
}

template <typename T>
void Dqueue<T>::insertFront(const T& val) {
    DobleNode<T>* newNode = new DobleNode<T>(val, front, NULL);
    if (this->front != NULL) {
        this->front->setPrev(newNode);
    }
    this->front = newNode;
    if (this->back == NULL) {
        this->back = newNode;
    }
    this->size++; 
}

template <typename T>
void Dqueue<T>::insertBack(const T& val) {
    DobleNode<T>* newNode = new DobleNode<T>(val, NULL, back);
    if (this->back != NULL) {
        this->back->setNext(newNode);
    }
    this->back = newNode;
    if (this->front == NULL) {
        this->front = newNode;
    }
    this->size++;
}

template <typename T>
T Dqueue<T>::deleteFront() {
    if (this->isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    T val = this->front->getVal();
    DobleNode<T>* temp = this->front;
    this->front = this->front->getNext();
    if (this->front != NULL) {
        this->front->setPrev(NULL);
    }
    else {
        this->back = NULL; // If the queue is now empty, set back to NULL
    }
    delete temp;
    size--;
    return val;
}

template <typename T>
T Dqueue<T>::deleteBack() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    T val = this->back->getVal();
    DobleNode<T>* temp = this->back;
    this->back = this->back->getPrev();
    if (this->back != NULL) {
        this->back->setNext(NULL);
    }
    else {
        this->front = NULL; // If the queue is now empty, set front to NULL
    }
    delete temp;
    size--;
    return val;
}

template <typename T>
T Dqueue<T>::getFront() {
    if (this->isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return this->front->getVal();
}

template <typename T>
T Dqueue<T>::getBack() {
    if (this->isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return this->back->getVal();
}

template <typename S>
std::ostream& operator<<(std::ostream& os, const Dqueue<S>& queue) {
    DobleNode<S>* current = queue.front;
    os << "Dqueue:[ ";
    while (current != NULL) {
        os << current->getVal() << " ";
        current = current->getNext();
    }
    os << "]";
    return os;
}

template <typename T>
Dqueue<T>::~Dqueue() {
    this->clear();
}

template <typename T>
void Dqueue<T>::clear() {
    while (!this->isEmpty()) {
        this->deleteFront();
    }
}   


#endif // LPC_DQUEUE_CPP