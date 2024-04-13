#include "CityNamesList.h"

/*CityNamesList::~CityNamesList()
{

}*/

CityNamesList* CityNamesList::add(char* c, Para position)
{
    CityNamesList* tmp = new CityNamesList;
    tmp->cityName = c;
    tmp->position = position;
    tmp->next = this;
    return tmp;
}

char* CityNamesList::get(Para position)
{
    if (this == nullptr)
        return nullptr;
    CityNamesList* head = this;
    while (head != nullptr)
    {
        if (position == head->position)
        {
            return head->cityName;
        }
        head = head->next;
    }
    return nullptr;
}