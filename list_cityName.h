#pragma once
class list_cityName
{
private:
    char* name;
    list_cityName* next;
public:
    ~list_cityName();
    list_cityName* push_front(char* name);
    list_cityName* pop_front(char** name);
    void write();
};