#pragma once
#include"friends_list.h"

class list_of_HashElements
{
private:
    char* c;
    int hashing;
    friends_list* friends;
    list_of_HashElements* next;
    int hashGenerate(char* c);
public:
    //~list_of_HashElements();
    list_of_HashElements* add(char* c, friends_list* friends);
    friends_list* get(char* c);
    void setFriendsList(friends_list* new_list, char* c);
};