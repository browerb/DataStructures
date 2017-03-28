#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class ListNode
{
    template <class U> friend class LinkedList;

public:

    ListNode(): next(nullptr), prev(nullptr){}
    ListNode(T val): next(nullptr), prev(nullptr), data(val){}
    ListNode(const ListNode <T> & rhs): next(nullptr), prev(nullptr), data(rhs.data){}

private:

    ListNode<T> * next;
    ListNode<T> * prev;
    T data;
};

template <class T>
class Iterator{

    template <class U> friend class LinkedList;

public:

    bool operator== (Iterator<T>&);
    bool operator!= (Iterator<T>&);

    Iterator<T>& operator++ ();
    Iterator<T>& operator-- ();
    T& operator* ();

private:

    ListNode<T> * node;
    Iterator(ListNode<T> * pos): node(pos){}
};

template <class T>
class LinkedList
{

public:

    LinkedList();
    LinkedList(T);
    LinkedList(const LinkedList<T>&);

    Iterator<T> begin();
    Iterator<T> end();

    void remove(int);
    void removeFront();
    void removeBack();

    void add(T&, int);
    void addToFront(T&);
    void addToBack(T&);

    LinkedList<T>& operator=(LinkedList<T>&);

    T& operator[](int);
    T get(int);
    int size();
    bool isEmpty();

    ~LinkedList();

private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int numElements;

};

#endif // LINKEDLIST_H
