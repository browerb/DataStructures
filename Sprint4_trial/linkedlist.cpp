#include "linkedlist.h"

template <class T>

LinkedList<T>::LinkedList()
{
    numElements = 0;
    head = new ListNode<T>();
    tail = new ListNode<T>();
}

template <class T>
LinkedList<T>::LinkedList(T)
{

}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>&)
{

}

template <class T>
Iterator<T>* LinkedList<T>::begin()
{
    Iterator<T> *it = new Iterator<T>(head);
    return it;
}

template <class T>
Iterator<T>* LinkedList<T>::end()
{
    Iterator<T> *it = new Iterator<T>(tail);
    return it;
}

template <class T>
void LinkedList<T>::remove(int index)
{
    if(isEmpty())
    {
        return false;
    }
}

template <class T>
void LinkedList<T>::remove(ListNode<T> del)
{
    if(isEmpty())
    {
        return false;
    }
    else
    {

    }
}

template <class T>
void LinkedList<T>::removeFront()
{
    if(isEmpty())
    {
        return false;
    }
}

template <class T>
void LinkedList<T>::removeBack()
{
    if(isEmpty())
    {
        return false;
    }
}

template <class T>
void LinkedList<T>::add(T&, int)
{

}

template <class T>
void LinkedList<T>::addToFront(T& data)
{
    if(isEmpty())
    {
        ListNode<T>* newFirst = new ListNode<T>(data);
        head->next = newFirst;
        tail->prev = newFirst;
    }
    else
    {
        ListNode<T> * oldFirst = head->next;
        ListNode<T> * newFirst = new ListNode<T>(data, oldFirst);
        oldFirst-> prev = newFirst;
        head->next = newFirst;
    }
}

template <class T>
void LinkedList<T>::addToBack(T& data)
{
    if(isEmpty())
    {
        ListNode<T>* newLast = new ListNode<T>(data);
        head->next = newLast;
        tail->prev = newLast;
    }
    else
    {
        ListNode<T> * oldLast = tail->prev;
        ListNode<T> * newLast = new ListNode<T>(data, nullptr, oldLast);
        oldLast-> next = newLast;
        tail->prev = newLast;
    }

}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&)
{

}

template <class T>
T& LinkedList<T>::operator[](int)
{

}

template <class T>
T LinkedList<T>::get(int)
{

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
bool LinkedList<T>::clear()
{
    while (tail->prev != nullptr)
    {
        ListNode<T> * temp = tail->prev;
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


/*
NodeList::Iterator::Iterator(Node* u) // constructor from Node*
{ v = u; }
Elem& NodeList::Iterator::operator*() // reference to the element
{ return v−>elem; } // compare positions
bool NodeList::Iterator::operator==(const Iterator& p) const
{ return v == p.v; }
bool NodeList::Iterator::operator!=(const Iterator& p) const
{ return v != p.v; } // move to next position
NodeList::Iterator& NodeList::Iterator::operator++()
{ v = v−>next; return *this; } // move to previous position
NodeList::Iterator& NodeList::Iterator::operator−−()
{ v = v−>prev; return *this; }
*/
