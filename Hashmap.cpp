#include "Hashmap.h"

using namespace std;

Hashmap::Hashmap(int size) :size(size)
{
    list = new list_of_HashElements * [size];
    for (int i = 0; i < size; i++)
        list[i] = nullptr;
}

Hashmap::~Hashmap()
{
    for (int i = 0; i < size; i++)
        delete[]list[i];
    delete[]list;
    list = nullptr;
}

void Hashmap::put(char* c, friends_list* friends)
{
    if (c == nullptr)
        return;
    int licz = hash(c);
    list[licz] = list[licz]->add(c, friends);
}

void Hashmap::addOne(char* c1, char* c2, int distance)
{
    if (c1 == nullptr || c2 == nullptr)
        return;
    int licz = hash(c1);
    friends_list* fr = list[licz]->get(c1)->push(distance, c2);
    list[licz]->setFriendsList(fr, c1);
}

friends_list* Hashmap::get(char* c)
{
    if (c == nullptr)
        return nullptr;
    int licz = hash(c);
    return list[licz]->get(c);
}

int Hashmap::hash(char* c)
{
    if (c[1] == '\0')
        return c[0] % size;
    else if (c[2] == '\0')
        return c[0] * c[1] % size;
    else
        return c[0] * c[1] * c[2] % size;
}