#pragma once
#include"list_of_HashElements.h"
#include"Para.h"

class Hashmap
{
private:
    int size;
    list_of_HashElements** list;
public:
    Hashmap(int size);
    ~Hashmap();
    void put(char* c, friends_list* friends);
    void addOne(char* c1, char* c2, int distance);
    friends_list* get(char* c);
    int hash(char* c);
};