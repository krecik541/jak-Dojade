#pragma once
#include "list.h"

template<typename T>
class queue {
private:
    int size;
    list<T>* head;
    list<T>* tail;
public:
    queue();
    void push(T toAdd);
    T pop();
    T front();
    T back();
    int getSize();
};

template<typename T>
inline queue<T>::queue()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
inline void queue<T>::push(T toAdd)
{
    size++;
	list<T>* tmp = new list<T>;
    tmp->elem = toAdd;
    tmp->next = nullptr;
    if(tail != nullptr)
        tail->next = tmp;
    else
        head = tmp;
    tail = tmp;
}

template<typename T>
inline T queue<T>::pop()
{
    size--;
    T elem;
    head = head->pop(elem);
    if (head == nullptr)
        tail = nullptr;
    return elem;
}

template<typename T>
inline T queue<T>::front()
{
    return head->elem;
}

template<typename T>
inline T queue<T>::back()
{
	return tail->elem;
}

template<typename T>
inline int queue<T>::getSize()
{
    return size;
}
