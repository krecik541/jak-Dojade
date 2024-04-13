#include "list_city_distance.h"
#include "funkcje.h"
#include<iostream>

using namespace std;

list_city_distance::~list_city_distance()
{
    name = nullptr;
    delete name;
    next = nullptr;
    //delete next;
}

list_city_distance* list_city_distance::push_end(int dis, char* name)
{
    list_city_distance* tmp = new list_city_distance, * head = this;
    tmp->distance = dis;
    tmp->name = name;
    if (head == nullptr)
    {
        tmp->next = nullptr;
        return tmp;
    }
    if (dis <= head->distance)
    {
        tmp->next = head;
        return tmp;
    }
    if (head->next == nullptr)
    {
        head->next = tmp;
        tmp->next = nullptr;
        return head;
    }
    while (head->next != nullptr)
    {
        if (dis <= head->next->distance)
        {
            tmp->next = head->next;
            head->next = tmp;
            break;
        }
        head = head->next;
    }
    return this;
}

list_city_distance* list_city_distance::pop_front(char** name, int& distance)
{
    if (this == nullptr)
        return nullptr;
    list_city_distance* tmp_next = this->next;
    *name = this->name;
    distance = this->distance;
    delete this;
    return tmp_next;
}

void list_city_distance::wypisz()
{
    list_city_distance* head = this;
    while (head != nullptr)
    {
        cout << head->name << " " << head->distance << " ";
        head = head->next;
    }
    cout << endl;
}