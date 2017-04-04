#ifndef STACK
#define STACK

#include "linkedlist.h"

template<class T>
class Stack
{
    public:
        T pop();
        T peek();
        void push(T);
        bool isEmpty();

    private:
        LinkedList<T> data;
        Node<T> * top;
};

template <class T>
T Stack<T>::pop(){
    T newTop = top->data;
    Node<T> * temp = top;
    top = top->next;
    temp -> next = nullptr;
    delete temp;
    return newTop;
}

template <class T>
T Stack<T>::peek(){
    return top->data;
}

template <class T>
void Stack<T>::push(T ins){
    Node<T> * temp;
    temp->data=ins;
    temp -> next = top;
    top = temp;
}

template <class T>
bool Stack<T>::isEmpty(){
    return top == nullptr;
}

#endif
