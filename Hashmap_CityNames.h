#pragma once
#include"CityNamesList.h"

/// <summary>
/// 
/// </summary>

class Hashmap_CityNames
{
private:
    int size;
    CityNamesList** list;
public:
    Hashmap_CityNames(int size);
    ~Hashmap_CityNames();
    void put(char* c, Para positions);
    char* get(Para position);
    int hash(Para position);
};