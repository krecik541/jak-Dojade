#pragma once
class list_city_distance
{
private:
    int distance;
    char* name;
    list_city_distance* next;
public:
    ~list_city_distance();
    list_city_distance* push_end(int dis, char* name);
    list_city_distance* pop_front(char** name, int& distance);
    void wypisz();
};