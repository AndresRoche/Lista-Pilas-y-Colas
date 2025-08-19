#include <iostream>
#include "DobleNode.cpp"

#ifndef LPC_LIST_CPP
#define LPC_LIST_CPP

template <typename T>
class List
{
private:
    int size;
    DobleNode<T> *head;
    DobleNode<T> *tail;

public:
    List() : size(0), head(NULL), tail(NULL) {}
    List(const List<T> &other);
    ~List();

    void insertFront(const T &val);
    void insertBack(const T &val);
    void insert(const T &val, const int &index);

    void removeFront();
    void removeBack();
    void removeByValue(const T &val);
    void removeByIndex(const int &index);
    void removeAll(const T &val);

    int find(const T& val);
    T getFront();
    T getBack();
    T getByIndex(const int &index);
    T &operator[](const int &index);

    bool operator==(const List<T>& other)  ;
    bool operator!=(const List<T>& other)  ;

    void swap(const int &index1, const int &index2);
    void reverse();
    void extend(const List<T> &other);
    void copy(const List<T> &other);

    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }
    void clear();

    template <typename S>
    friend std::ostream &operator<<(std::ostream &os, const List<S> &list);

    
};

template <typename T>
List<T>::List(const List<T> &other) : size(other.size), head(NULL), tail(NULL)
{
    if (other.head == NULL)
    {
        return;
    }

    this->head = new DobleNode<T>(other.head->getVal());
    DobleNode<T> *currentOther = other.head->getNext();
    DobleNode<T> *currentThis = this->head;

    while (currentOther != NULL)
    {
        currentThis->setNext(new DobleNode<T>(currentOther->getVal()));
        currentThis->getNext()->setPrev(currentThis);

        // Move to the next node
        currentThis = currentThis->getNext();
        currentOther = currentOther->getNext();
    }

    this->tail = currentThis;
}

template <typename T>
List<T>::~List()
{
    this->clear();
}

template <typename T>
void List<T>::insertFront(const T &val)
{
    DobleNode<T> *newNode = new DobleNode<T>(val, head, NULL);
    if (this->head != NULL)
    {
        this->head->setPrev(newNode);
    }
    this->head = newNode;
    if (this->tail == NULL)
    {
        this->tail = newNode;
    }
    this->size++;
}

template <typename T>
void List<T>::insertBack(const T &val)
{
    DobleNode<T> *newNode = new DobleNode<T>(val, NULL, tail);
    if (this->tail != NULL)
    {
        this->tail->setNext(newNode);
    }
    this->tail = newNode;
    if (this->head == NULL)
    {
        this->head = newNode;
    }
    this->size++;
}

template <typename T>
void List<T>::insert(const T &val, const int &index)
{
    if (index < 0 || index > size)
    {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0)
    {
        this->insertFront(val);
        return;
    }
    if (index == size)
    {
        this->insertBack(val);
        return;
    }

    DobleNode<T> *current = this->head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->getNext();
    }

    DobleNode<T> *newNode = new DobleNode<T>(val, current->getNext(), current);
    if (current->getNext() != NULL)
    {
        current->getNext()->setPrev(newNode);
    }
    current->setNext(newNode);
    this->size++;
}

template <typename T>
void List<T>::removeFront()
{
    if (this->head == NULL)
    {
        throw std::out_of_range("List is empty");
    }
    DobleNode<T> *toDelete = this->head;
    this->head = this->head->getNext();
    if (this->head != NULL)
    {
        this->head->setPrev(NULL);
    }
    else
    {
        this->tail = NULL;
    }
    delete toDelete;
    this->size--;
}

template <typename T>
void List<T>::removeBack()
{
    if (this->tail == NULL)
    {
        throw std::out_of_range("List is empty");
    }
    DobleNode<T> *toDelete = this->tail;
    this->tail = this->tail->getPrev();
    if (this->tail != NULL)
    {
        this->tail->setNext(NULL);
    }
    else
    {
        this->head = NULL;
    }
    delete toDelete;
    this->size--;
}

template <typename T>
int List<T>::find(const T &val)
{
    DobleNode<T> *current = this->head;
    int i = 0;
    while (current != NULL)
    {
        if (current->getVal() == val)
        {
            return i; 
        }
        current = current->getNext();
        i++;
    }

    return -1;
}

template <typename T>
void List<T>::removeByValue(const T &val)
{
    DobleNode<T> *current = this->head;
    while (current != NULL)
    {
        if (current->getVal() == val)
        {
            if (current->getPrev() != NULL)
            {
                current->getPrev()->setNext(current->getNext());
            }
            else
            {
                this->head = current->getNext();
            }
            if (current->getNext() != NULL)
            {
                current->getNext()->setPrev(current->getPrev());
            }
            else
            {
                this->tail = current->getPrev();
            }
            delete current;
            this->size--;
            return; 
        }
        current = current->getNext();
    }
}

template <typename T>
void List<T>::removeAll(const T &val)
{
    DobleNode<T> *current = this->head;
    while (current != NULL)
    {
        DobleNode<T> *nextNode = current->getNext(); // Store next node before deletion
        if (current->getVal() == val)
        {
            if (current->getPrev() != NULL)
            {
                current->getPrev()->setNext(current->getNext());
            }
            else
            {
                this->head = current->getNext();
            }
            if (current->getNext() != NULL)
            {
                current->getNext()->setPrev(current->getPrev());
            }
            else
            {
                this->tail = current->getPrev();
            }
            delete current;
            this->size--;
        }
        current = nextNode; // Move to the next node
    }
    if (this->size == 0)
    {
        this->head = NULL;
        this->tail = NULL;
    }
    else if (this->head == NULL)
    {
        this->tail = NULL; // If head is NULL, tail should also be NULL
    }
    else if (this->tail == NULL)
    {
        this->head = NULL; // If tail is NULL, head should also be NULL
    }
    // No need to check if size is 0, as it will be handled by the next operations
    else if (this->head == this->tail)
    {
        this->head = this->tail = NULL; // If both head and tail are the same, set them to NULL
    }  
}

template <typename T>
void List<T>::removeByIndex(const int &index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0)
    {
        this->removeFront();
        return;
    }
    if (index == size - 1)
    {
        this->removeBack();
        return;
    }

    DobleNode<T> *current = this->head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }

    if (current->getPrev() != NULL)
    {
        current->getPrev()->setNext(current->getNext());
    }
    if (current->getNext() != NULL)
    {
        current->getNext()->setPrev(current->getPrev());
    }
    delete current;
    this->size--;
}

template <typename T>
void List<T>::clear()
{
    while (this->head != NULL)
    {
        this->removeFront();
    }
}

template <typename T>
T List<T>::getFront()
{
    if (this->head == NULL)
    {
        throw std::out_of_range("List is empty");
    }
    return this->head->getVal();
}

template <typename T>
T List<T>::getBack()
{
    if (this->tail == NULL)
    {
        throw std::out_of_range("List is empty");
    }
    return this->tail->getVal();
}

template <typename T>
T List<T>::getByIndex(const int& index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    
    DobleNode<T> *current = this->head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }
    
    if (current == NULL)
    {
        throw std::out_of_range("Index out of range");
    }
    
    return current->getVal();
}

template <typename T>
T &List<T>::operator[](const int& index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    
    DobleNode<T> *current = this->head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }
    
    if (current == NULL)
    {
        throw std::out_of_range("Index out of range");
    }
    
    return current->getVal(); // Return reference to the value
}

//Creo que este no funciona
//has el swap pero que cambien de lugar los nodos
template <typename T>
void List<T>::swap(const int &index1, const int &index2)
{
    if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    if (index1 == index2)
    {
        return; // No need to swap the same index
    }

    DobleNode<T> *node1 = this->head;
    DobleNode<T> *node2 = this->head;

    for (int i = 0; i < index1; i++)
    {
        node1 = node1->getNext();
    }
    for (int i = 0; i < index2; i++)
    {
        node2 = node2->getNext();
    }

    T tempVal = node1->getVal();
    node1->setVal(node2->getVal());
    node2->setVal(tempVal);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &list)
{
    DobleNode<T> *current = list.head;
    os << "List:[ ";
    while (current != NULL)
    {
        os << current->getVal() << " ";
        current = current->getNext();
    }
    os << "]";
    return os;
}

template <typename T>
void List<T>::reverse()
{
    DobleNode<T> *current = this->head;
    DobleNode<T> *temp = NULL;

    while (current != NULL)
    {
        temp = current->getPrev();
        current->setPrev(current->getNext());
        current->setNext(temp);
        current = current->getPrev();
    }

    if (temp != NULL)
    {
        this->tail = this->head;
        this->head = temp->getPrev();
    }
}

template <typename T>
void List<T>::extend(const List<T> &other)
{
    if (other.head == NULL)
    {
        return; // Nothing to extend
    }

    if (this->head == NULL)
    {
        this->head = new DobleNode<T>(other.head->getVal());
        DobleNode<T> *currentOther = other.head->getNext();
        DobleNode<T> *currentThis = this->head;

        while (currentOther != NULL)
        {
            currentThis->setNext(new DobleNode<T>(currentOther->getVal()));
            currentThis->getNext()->setPrev(currentThis);

            // Move to the next node
            currentThis = currentThis->getNext();
            currentOther = currentOther->getNext();
        }

        this->tail = currentThis;
    }
    else
    {
        this->tail->setNext(new DobleNode<T>(other.head->getVal()));
        this->tail->getNext()->setPrev(this->tail);
        this->tail = this->tail->getNext();

        DobleNode<T> *currentOther = other.head->getNext();
        while (currentOther != NULL)
        {
            this->tail->setNext(new DobleNode<T>(currentOther->getVal()));
            this->tail->getNext()->setPrev(this->tail);
            this->tail = this->tail->getNext();
            currentOther = currentOther->getNext();
        }
    }

    this->size += other.size;
}


template <typename T>
void List<T>::copy(const List<T> &other)
{
    this->clear(); // Clear the current list before copying

    if (other.head == NULL)
    {
        return; // Nothing to copy
    }

    this->head = new DobleNode<T>(other.head->getVal());
    DobleNode<T> *currentOther = other.head->getNext();
    DobleNode<T> *currentThis = this->head;

    while (currentOther != NULL)
    {
        currentThis->setNext(new DobleNode<T>(currentOther->getVal()));
        currentThis->getNext()->setPrev(currentThis);

        // Move to the next node
        currentThis = currentThis->getNext();
        currentOther = currentOther->getNext();
    }

    this->tail = currentThis;
    this->size = other.size;
}


template <typename T>
bool List<T>::operator==(const List<T>& other)   {
    if (size != other.size) return false;

    DobleNode<T>* current1 = this->head;
    DobleNode<T>* current2 = other.head;

    while (current1 != NULL && current2 != NULL) {
        if (current1->getVal() != current2->getVal()) {
            return false;
        }
        current1 = current1->getNext();
        current2 = current2->getNext();
    }

    return true;
}


template <typename T>
bool List<T>::operator!=(const List<T>& other)   {
    return !(*this == other);
}

#endif // LPC_LIST_CPP