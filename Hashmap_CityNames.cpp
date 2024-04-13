#include "Hashmap_CityNames.h"

Hashmap_CityNames::Hashmap_CityNames(int size) : size(size)
{
    list = new CityNamesList * [size];
    for (int i = 0; i < size; i++)
        list[i] = nullptr;
}

Hashmap_CityNames::~Hashmap_CityNames()
{
    for (int i = 0; i < size; i++)
        delete[]list[i];
    delete[]list;
    list = nullptr;
}

void Hashmap_CityNames::put(char* c, Para positions)
{
    int licz = hash(positions);
    list[licz] = list[licz]->add(c, positions);
}

char* Hashmap_CityNames::get(Para position)
{
    int licz = hash(position);
    return list[licz]->get(position);
}

int Hashmap_CityNames::hash(Para position)
{
    return (position.x * 17 + position.y * 13) % size;
}