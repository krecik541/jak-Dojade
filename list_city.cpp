#include "list_city.h"
#include <iostream>

using namespace std;

list_city::list_city()
{
    position = { NULL, NULL };
    next = nullptr;
}

list_city::~list_city()
{
    if (next != nullptr)
    {
        next = nullptr;
        delete next;
    }
}

list_city* list_city::push_front(Para position)
{
    list_city* tmp = new list_city;
    tmp->position = position;
    tmp->next = this;
    return tmp;
}

list_city* list_city::pop_front(Para& pos)
{
    if (this == nullptr)
        return nullptr;
    list_city* tmp_next = this->next;
    pos = this->position;
    delete this;
    return tmp_next;
}