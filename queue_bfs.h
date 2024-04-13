#pragma once
#include"Para.h"

/// <summary>
/// this QUEUE is used in bfs function
/// </summary>

class queue_bfs
{
private:
    Para position;
    int distance;
    queue_bfs* next;
    queue_bfs* prev;
public:
    ~queue_bfs();
    queue_bfs* push(Para pos, int dis);
    queue_bfs* pop(Para& pos, int& dis);
};