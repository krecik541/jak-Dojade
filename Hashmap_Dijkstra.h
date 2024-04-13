#pragma once
#include"list_Dijkstra.h"
class Hashmap_Dijkstra
{
private:
    int size;
    list_Dijkstra** list;
public:
    Hashmap_Dijkstra(int size);
    ~Hashmap_Dijkstra();
    void put(char* c);
    void put(char* c, char* prev, int dis);
    list_Dijkstra* get(char* c);
    int hash(char* c);
};