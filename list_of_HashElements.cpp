#include "list_of_HashElements.h"
#include "funkcje.h"
#include<iostream>

using namespace std;

list_of_HashElements* list_of_HashElements::add(char* c, friends_list* friends)
{
    list_of_HashElements* tmp = new list_of_HashElements;
    tmp->c = c;
    tmp->friends = friends;
    tmp->next = this;
    ////tmp->hashing = hashGenerate(tmp->c);
    return tmp;
}

friends_list* list_of_HashElements::get(char* c)
{
    if (this == nullptr)
        return nullptr;
    list_of_HashElements* head = this;

    //int hashC = hashGenerate(c);

    while (head != nullptr)
    {
        if (/*hashC == head->hashing && */!strcmp(c, head->c))
        {
            //cout << hashC << " " << hashing << endl;
            return head->friends;
        }
        head = head->next;
    }
    return nullptr;
}

void list_of_HashElements::setFriendsList(friends_list* new_list, char* c)
{
    if (this == nullptr || c == nullptr)
        return;
    //int hashC = hashGenerate(c);
    list_of_HashElements* head = this;
    while (head != nullptr)
    {
        if (/*hashC == head->hashing && */!strcmp(c, head->c))
        {
            //cout << hashC << " " << hashing << endl;
            head->friends = new_list;
            break;
        }
        head = head->next;
    }
    return;
}

int list_of_HashElements::hashGenerate(char* c)
{
    if (c[1] == '\0')
        return c[0];
    if (c[2] == '\0')
        return c[0] - c[1];
    return c[0] + c[1] * c[2];
}