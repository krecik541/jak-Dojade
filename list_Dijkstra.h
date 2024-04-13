#pragma once
class list_Dijkstra
{
private:
    char* c;
    int distance;
    char* prev;
    list_Dijkstra* next;
public:
    list_Dijkstra* add(char* c, char* prev, int dis);
    list_Dijkstra* find(char* c);
    char* getPrev();
    int getDistane();
    void setPrev(char* prev);
    void setDistance(int dis);
};