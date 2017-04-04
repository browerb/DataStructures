#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
template <class T>
class Node
{
    template <class U> friend class LinkedList;

public:

    Node(): next(nullptr), prev(nullptr){}
    Node(T element): next(nullptr), prev(nullptr), data(element){}
    Node(const Node <T> & rhs): next(nullptr), prev(nullptr), data(rhs.data){}
    Node(T element,  Node <T> * _next = nullptr, Node<T> * _prev = nullptr): next(_next), prev(_prev), data(element){}

private:

    Node<T> * next;
    Node<T> * prev;
    T data;
};

template <class T>
class LinkedList
{

public:

    class Iterator{

        friend class LinkedList<T>;

    public:

        Iterator(Node <T> *, LinkedList<T> *);
        operator bool();
        bool operator== (Iterator&);
        bool operator!= (Iterator&);
        typename LinkedList<T>::Iterator& operator++ ();
        typename LinkedList<T>::Iterator& operator-- ();
        T& operator* ();

    private:

        Node<T> * node;
        LinkedList<T> * owner;
    };

    LinkedList();
    LinkedList(T);
    LinkedList(const LinkedList<T>&);

    Iterator* begin();
    Iterator* end();

    void remove(int);
    void remove(Iterator&);
    void removeFront();
    void removeBack();

    void addAt(T&, int);
    void addToFront(T&);
    void addToBack(T&);

    LinkedList<T>& operator=(LinkedList<T>&);

    T& operator[](int);
    T get(int);
    T first();
    T last();
    int size();
    bool isEmpty();


    void clear();
    ~LinkedList();

private:
    Node<T>* head;
    Node<T>* tail;
    int numElements;

};
template <class T>
LinkedList<T>::LinkedList()
{
    numElements = 0;
    head = new Node<T>();
    tail = new Node<T>();
    head ->next = tail;
    tail-> prev = head;
}

template <class T>
LinkedList<T>::LinkedList(T data)
{
    numElements = 1;
    head = new Node<T>;
    tail = new Node<T>;
    Node<T> *node = new Node<T>(data, head, tail);

    head -> next = node;
    tail -> prev = node;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& llist)
{
    head = llist.head;
    tail = llist.tail;
    numElements = llist.numElements;
}

template <class T>
typename LinkedList<T>::Iterator * LinkedList<T>::begin()
{
    Iterator *it = new Iterator(head);
    return it;
}

template <class T>
typename LinkedList<T>::Iterator * LinkedList<T>::end()
{
    Iterator *it = new Iterator(tail);
    return it;
}

template <class T>
void LinkedList<T>::remove(int index)
{
    Node<T> *curr = head;
    if(index <= numElements)
    {
        for (int i = 0; i <= index; i++)
            curr = curr -> next;
        curr -> prev -> next = curr -> next;
        curr -> next-> prev = curr -> prev;

        curr -> next =curr-> prev = nullptr;
        delete curr;

        numElements--;
    }
}

template <class T>
void LinkedList<T>::remove(Iterator& iter)
{
    Node<T> * temp = iter.node;
    ++iter;

    temp->prev->next =temp->next;
    temp->next->prev = temp->prev;

    temp -> next = temp -> prev = nullptr;
    delete temp;

    numElements--;

}

template <class T>
void LinkedList<T>::removeFront()
{
    Node<T> *curr = head -> next;
    head -> next = curr -> next;
    curr -> next -> prev = head;

    curr -> next =curr-> prev = nullptr;
    delete curr;

    numElements--;
}

template <class T>
void LinkedList<T>::removeBack()
{
    if(!isEmpty())
    {
        Node<T> *curr = tail -> prev;
        tail -> prev = curr -> prev;
        curr -> prev -> next = tail;

        curr -> next =curr-> prev = nullptr;
        delete curr;

        numElements--;
    }
}

template <class T>
void LinkedList<T>::addAt(T& data, int index)
{
    Node<T> *curr = head;
    if(index > 0 && index <= numElements)
    {
        for (int i = 0; i < index; i++)
            if(curr-> next != tail)
                curr = curr -> next;
    }
    Node<T> *newNode = new Node<T>(data);
    newNode->next = curr -> next;
    newNode -> prev = curr;
    curr->next = newNode;
    numElements++;

}

template <class T>
void LinkedList<T>::addToFront(T& data)
{
    if(isEmpty())
    {
        Node<T>* newFirst = new Node<T>(data);
        head->next = newFirst;
        tail->prev = newFirst;
    }
    else
    {
        Node<T> * oldFirst = head->next;
        Node<T> * newFirst = new Node<T>(data, oldFirst);
        oldFirst-> prev = newFirst;
        head->next = newFirst;
    }
}

template <class T>
void LinkedList<T>::addToBack(T& data)
{
    if(isEmpty())
    {
        Node<T>* newLast = new Node<T>(data);
        head->next = newLast;
        tail->prev = newLast;
    }
    else
    {
        Node<T> * oldLast = tail->prev;
        Node<T> * newLast = new Node<T>(data, nullptr, oldLast);
        oldLast-> next = newLast;
        tail->prev = newLast;
    }

}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& rhs)
{
    if(!isEmpty())
        clear();

    LinkedList<T> list = new LinkedList<T>();
    list.head = rhs.head;
    list.tail = rhs.tail;
    list.numElements = rhs.numElements;

    return list;
}

template <class T>
T& LinkedList<T>::operator[](int index)
{
    
        Node<T> *curr = head;
        if(index > 0 && index <= numElements)
        {
            for (int i = 0; i < index; i++)
                curr = curr -> next;
        }
        return curr -> data;
    
}

template <class T>
T LinkedList<T>::get(int index)
{
    Node<T> *curr = head;
    if(index > 0 && index <= numElements)
    {
        for (int i = 0; i < index; i++)
            curr = curr -> next;
    }
    return curr -> data;
}

template <class T>
T LinkedList<T>::first(){
    return head -> next -> data;
}

template <class T>
T LinkedList<T>::last(){
    return tail -> prev -> data;
}

template <class T>
int LinkedList<T>::size()
{
    return numElements;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return (head-> next == nullptr);
}

template <class T>
void LinkedList<T>::clear()
{
    while (tail->prev != nullptr)
    {
        Node<T> * temp = tail->prev;
        tail->prev = temp->prev;
        delete temp;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    clear();
    delete head;
    delete tail;
}

template <class T>
LinkedList<T>::Iterator::Iterator(Node<T>* node, LinkedList<T> * owner) : node( node ), owner ( owner ){}

template <class T>
LinkedList<T>::Iterator::operator bool()
{
    return (node != owner -> head);
}

template <class T>
T& LinkedList<T>::Iterator::operator*()
{
    return node -> data;
}

template <class T>
bool LinkedList<T>::Iterator::operator==(Iterator& rhs)
{
    return node == rhs.node;
}

template <class T>
bool LinkedList<T>::Iterator::operator!=( Iterator& rhs)
{
    return !operator==(rhs);
}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++()
{
    if (operator bool())
        node = node-> next;
    return * this;
}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--()
{
    if (node != owner -> tail)
        node = node-> prev;
    return * this;
}


#endif // LINKEDLIST_H
