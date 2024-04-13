#include "friends_list.h"

using namespace std;

friends_list::friends_list()
{
    distance = 0;
    next = nullptr;
    friends = nullptr;
}

friends_list::~friends_list()
{
    next = nullptr;
    delete next;
    delete[]friends;
}

friends_list* friends_list::push(int dis, char* friends)
{
    friends_list* tmp = new friends_list;
    tmp->friends = friends;
    tmp->distance = dis;
    tmp->next = this;
    return tmp;
}

friends_list* friends_list::get_at_pos(int pos)
{
    friends_list* head = this;
    int i = 0;
    while (i != pos && head != nullptr)
    {
        head = head->next;
        i++;
    }
    return head;
}

int friends_list::get_dis()
{
    return distance;
}

char* friends_list::getFriend()
{
    return friends;
}