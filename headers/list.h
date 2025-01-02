#pragma once

template<typename T>
class queue;

template<typename K, typename V>
class hashmap;

template<typename T>
class list {
protected:
    T elem;
    list<T>* next;
public:
    list();
    int hashGenerate();
    list<T>* push(T toAdd);
    list<T>* pop(T& elem);
    list<T>* pop_without_delete(T& elem);
    list<T>* pop(int index, T& elem);
    void set(int index, T toChange);
    list<T>* find(int index, list<T>* head);
    void print();
    T getElem();
    list<T>* getNext();

    friend class queue<T>;

    template<typename K, typename V>
    friend class hashmap;
};

template<typename T> list<T>::list()
{

}

template<typename T> int list<T>::hashGenerate() {
    return elem.hashCode();
}

template<typename T> list<T>* list<T>::push(T toAdd) {
    list<T>* tmp = new list<T>;
    tmp->next = this;
    tmp->elem = toAdd;
    return tmp;
}

template<typename T> list<T>* list<T>::pop(T& elem) {
    elem = this->elem;
    list<T>* tmp = this->next;
    delete this;
    return tmp;
}

template<typename T>
inline list<T>* list<T>::pop_without_delete(T& elem)
{
    if (this == nullptr)
        return nullptr;
    list<T>* tmp = this->next;
    elem = this->elem;
    return tmp;
}

template<typename T> list<T>* list<T>::pop(int index, T& elem) {
    list<T>* head = this, tmp = this;
    if (index == 0)
    {
        elem = head->elem;
        tmp = head->next;
        delete head;
        return tmp;
    }

    for (int i = 0; i < index; i++)
        if (head != nullptr)
        {
            tmp = head;
            head = head->next;
        }
        else
            break;

    tmp->next = head ? head->next : nullptr;
    elem = head->elem;
    delete head;

    return this;
}

template<typename T> void list<T>::set(int index, T toChange) {
    list* tmp = find(index, this);
    tmp->elem = toChange;
}

template<typename T> list<T>* list<T>::find(int index, list* head) {
    list* tmp = head;

    for (int i = 0; i < index; i++)
        if (tmp != nullptr)
            tmp = tmp->next;
        else
            break;

    return tmp;
}

template<typename T> void list<T>::print() {
    list<T>* head = this;

    while (head != nullptr)
    {
        //std::cout << head->elem << std::endl;
        head = head->next;
    }
}

template<typename T> T list<T>::getElem() {
    return this->elem;
}

template<typename T> list<T>* list<T>::getNext() {
    return this->next;
}