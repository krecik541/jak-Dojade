#include "Hashmap_Dijkstra.h"
#include"funkcje.h"

Hashmap_Dijkstra::Hashmap_Dijkstra(int size) : size(size)
{
    list = new list_Dijkstra * [size];
    for (int i = 0; i < size; i++)
        list[i] = nullptr;
}

Hashmap_Dijkstra::~Hashmap_Dijkstra()
{
    for (int i = 0; i < size; i++)
        delete[]list[i];
    delete[]list;
    list = nullptr;
}

void Hashmap_Dijkstra::put(char* c)
{
    if (c == nullptr)
        return;
    int licz = hash(c);
    list[licz] = list[licz]->add(c, nullptr, MAX);
}

void Hashmap_Dijkstra::put(char* c, char* prev, int dis)
{
    if (c == nullptr)
        return;
    int licz = hash(c);
    list[licz] = list[licz]->add(c, prev, dis);
}

list_Dijkstra* Hashmap_Dijkstra::get(char* c)
{
    if (c == nullptr)
        return nullptr;
    int licz = hash(c);
    return list[licz]->find(c);
}

int Hashmap_Dijkstra::hash(char* c)
{
    if (c[1] == '\0')
        return c[0] % size;
    else if (c[2] == '\0')
        return c[0] * c[1] % size;
    else
        return c[0] * c[1] * c[2] % size;
}