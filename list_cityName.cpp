#include "list_cityName.h"
#include<iostream>

using namespace std;

list_cityName::~list_cityName()
{
    if (name != nullptr)
    {
        delete[]name;
        name = nullptr;
    }
    if (next != nullptr)
    {
        next = nullptr;
        delete next;
    }
}

list_cityName* list_cityName::push_front(char* name)
{
    list_cityName* tmp = new list_cityName;
    tmp->name = name;
    tmp->next = this;
    return tmp;
}

list_cityName* list_cityName::pop_front(char** name)
{
    if (this == nullptr)
        return nullptr;
    list_cityName* tmp_next = this->next;
    *name = this->name;
    //delete this;
    return tmp_next;
}

void list_cityName::write()
{
    char* c = nullptr;
    list_cityName* head = this->next;
    while (head->next != nullptr)
    {
        head = head->pop_front(&c);
        cout << c << " ";
    }
    pop_front(&c);
}