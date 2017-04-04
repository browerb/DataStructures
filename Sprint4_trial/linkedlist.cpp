//#include "linkedlist.h"
//template <class T>
//LinkedList<T>::LinkedList()
//{
//    numElements = 0;
//    head = new Node<T>();
//    tail = new Node<T>();
//    head ->next = tail;
//    tail-> prev = head;
//}

//template <class T>
//LinkedList<T>::LinkedList(T data)
//{
//    numElements = 1;
//    head = new Node<T>;
//    tail = new Node<T>;
//    Node<T> *node = new Node<T>(data, head, tail);

//    head -> next = node;
//    tail -> prev = node;
//}

//template <class T>
//LinkedList<T>::LinkedList(const LinkedList<T>& llist)
//{
//    head = llist.head;
//    tail = llist.tail;
//    numElements = llist.numElements;
//}

//template <class T>
//typename LinkedList<T>::Iterator * LinkedList<T>::begin()
//{
//    Iterator *it = new Iterator(head);
//    return it;
//}

//template <class T>
//typename LinkedList<T>::Iterator * LinkedList<T>::end()
//{
//    Iterator *it = new Iterator(tail);
//    return it;
//}

//template <class T>
//void LinkedList<T>::remove(int index)
//{
//    Node<T> *curr = head;
//    if(index <= numElements)
//    {
//        for (int i = 0; i <= index; i++)
//            curr = curr -> next;
//        curr -> prev -> next = curr -> next;
//        curr -> next-> prev = curr -> prev;
//        delete curr;
//        numElements--;
//    }
//}

//template <class T>
//void LinkedList<T>::remove(Node<T> node)
//{

//}

//template <class T>
//void LinkedList<T>::removeFront()
//{
//    if(!isEmpty())
//    {

//    }
//}

//template <class T>
//void LinkedList<T>::removeBack()
//{
//    if(!isEmpty())
//    {
//        Node<T> *curr = head -> next;
//        head -> next = curr -> next;
//        curr -> next -> prev = head;
//        delete curr;
//        numElements--;
//    }
//}

//template <class T>
//void LinkedList<T>::addAt(T& data, int index)
//{
//    Node<T> *curr = head;
//    if(index > 0 && index <= numElements)
//    {
//        for (int i = 0; i < index; i++)
//            if(curr-> next != tail)
//                curr = curr -> next;
//    }
//    Node<T> *newNode = new Node<T>(data);
//    newNode->next = curr -> next;
//    newNode -> prev = curr;
//    curr->next = newNode;
//    numElements++;

//}

//template <class T>
//void LinkedList<T>::addToFront(T& data)
//{
//    if(isEmpty())
//    {
//        Node<T>* newFirst = new Node<T>(data);
//        head->next = newFirst;
//        tail->prev = newFirst;
//    }
//    else
//    {
//        Node<T> * oldFirst = head->next;
//        Node<T> * newFirst = new Node<T>(data, oldFirst);
//        oldFirst-> prev = newFirst;
//        head->next = newFirst;
//    }
//}

//template <class T>
//void LinkedList<T>::addToBack(T& data)
//{
//    if(isEmpty())
//    {
//        Node<T>* newLast = new Node<T>(data);
//        head->next = newLast;
//        tail->prev = newLast;
//    }
//    else
//    {
//        Node<T> * oldLast = tail->prev;
//        Node<T> * newLast = new Node<T>(data, nullptr, oldLast);
//        oldLast-> next = newLast;
//        tail->prev = newLast;
//    }

//}

//template <class T>
//LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&)
//{

//}

//template <class T>
//T& LinkedList<T>::operator[](int)
//{

//}

//template <class T>
//T LinkedList<T>::get(int index)
//{
//    Node<T> *curr = head;
//    if(index > 0 && index <= numElements)
//    {
//        for (int i = 0; i < index; i++)
//            curr = curr -> next;
//    }
//    return curr -> data;
//}

//template <class T>
//T LinkedList<T>::first(){
//    return head -> next -> data;
//}

//template <class T>
//T LinkedList<T>::last(){
//    return tail -> prev -> data;
//}

//template <class T>
//int LinkedList<T>::size()
//{
//    return numElements;
//}

//template <class T>
//bool LinkedList<T>::isEmpty()
//{
//    return (head-> next == nullptr);
//}

//template <class T>
//void LinkedList<T>::clear()
//{
//    while (tail->prev != nullptr)
//    {
//        Node<T> * temp = tail->prev;
//        tail->prev = temp->prev;
//        delete temp;
//    }
//}

//template <class T>
//LinkedList<T>::~LinkedList()
//{
//    clear();
//    delete head;
//    delete tail;
//}

////template <class T>
////Iterator::Iterator(Node<T>* node) // constructor from Node*
////{

////}

////template <class T>
////T& Iterator::operator*()
////{

////}

////template <class T>
////bool Iterator::operator==( Iterator& pos)
////{

////}

////template <class T>
////bool Iterator::operator!=( Iterator& pos)
////{

////}

////template <class T>
////Iterator& Iterator::operator++()
////{

////}

////template <class T>
////Iterator& Iterator::operator−−()
////{

////}

