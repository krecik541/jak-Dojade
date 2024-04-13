#pragma once

class friends_list
{
private:
    int distance;
    char* friends;
    friends_list* next;
public:
    friends_list();
    ~friends_list();
    friends_list* push(int dis, char* friends);
    friends_list* get_at_pos(int pos);
    int get_dis();
    char* getFriend();
};