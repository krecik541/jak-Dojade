#include "list_Dijkstra.h"
#include "funkcje.h"
#include<string>

list_Dijkstra* list_Dijkstra::add(char* c, char* prev, int dis)
{
    list_Dijkstra* tmp = new list_Dijkstra;
    tmp->c = c;
    tmp->prev = prev;
    tmp->distance = dis;
    tmp->next = this;
    return tmp;
}

list_Dijkstra* list_Dijkstra::find(char* c)
{
    list_Dijkstra* head = this;
    while (head != nullptr)
    {
        if (!strcmp(c, head->c))
        {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

char* list_Dijkstra::getPrev()
{
    return prev;
}

int list_Dijkstra::getDistane()
{
    return distance;
}

void list_Dijkstra::setPrev(char* prev)
{
    this->prev = prev;
}

void list_Dijkstra::setDistance(int dis)
{
    this->distance = dis;
}