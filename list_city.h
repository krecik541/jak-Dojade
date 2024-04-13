#pragma once
#include "Para.h"

/// <summary>
/// this List is used to hold the positions of the cities
/// </summary>

class list_city
{
private:
    Para position;
    list_city* next;
public:
    list_city();
    ~list_city();
    list_city* push_front(Para position);
    list_city* pop_front(Para& pos);
};