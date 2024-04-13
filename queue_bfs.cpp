#include "queue_bfs.h"

using namespace std;

queue_bfs::~queue_bfs()
{
    next = nullptr;
    delete next;
    prev = nullptr;
    delete prev;
}

queue_bfs* queue_bfs::push(Para pos, int dis)
{
    queue_bfs* tmp = new queue_bfs;
    tmp->position = pos;
    tmp->distance = dis;
    tmp->prev = this;
    tmp->next = nullptr;
    if (this != nullptr)
        this->next = tmp;
    return tmp;
}

queue_bfs* queue_bfs::pop(Para& pos, int& dis)
{
    if (this == nullptr)
        return nullptr;
    queue_bfs* next = this->next;
    if (next == nullptr)
        return nullptr;
    pos = next->position;
    dis = next->distance;
    delete this;
    return next;
}