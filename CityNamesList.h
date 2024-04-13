#pragma once
#include"Para.h"

class CityNamesList
{
private:
    char* cityName;
    Para position;
    CityNamesList* next;
    int hashGenerate();
public:
    //~CityNamesList();
    CityNamesList* add(char* c, Para position);
    char* get(Para position);
};