#include "headers/funkcje.h"
#include "headers/queue.h"
#include "headers/hashmap.h"

#define X pos.key
#define Y pos.value
//city, distance, prev
#define CITY_NAME  getElem().key
#define DISTANCE getElem().value.key
#define PREV getElem().value.value

using namespace std;

char* getCityName(pair<int, int> pos, char** t, int w, int h)
{
    if (X - 1 >= 0 && ((t[X - 1][Y] >= 'A' && t[X - 1][Y] <= 'Z') || (t[X - 1][Y] >= '0' && t[X - 1][Y] <= '9')))
        X--;
    else if (X + 1 < h && ((t[X + 1][Y] >= 'A' && t[X + 1][Y] <= 'Z') || (t[X + 1][Y] >= '0' && t[X + 1][Y] <= '9')))
        X++;
    else if (Y - 1 >= 0 && ((t[X][Y - 1] >= 'A' && t[X][Y - 1] <= 'Z') || (t[X][Y - 1] >= '0' && t[X][Y - 1] <= '9')))
        Y--;
    else if (Y + 1 < w && ((t[X][Y + 1] >= 'A' && t[X][Y + 1] <= 'Z') || (t[X][Y + 1] >= '0' && t[X][Y + 1] <= '9')))
        Y++;
    else if (X - 1 >= 0 && Y - 1 >= 0 && ((t[X - 1][Y - 1] >= 'A' && t[X - 1][Y - 1] <= 'Z') || (t[X - 1][Y - 1] >= '0' && t[X - 1][Y - 1] <= '9')))
    {
        X--;
        Y--;
    }
    else if (X - 1 >= 0 && Y + 1 < w && ((t[X - 1][Y + 1] >= 'A' && t[X - 1][Y + 1] <= 'Z') || (t[X - 1][Y + 1] >= '0' && t[X - 1][Y + 1] <= '9')))
    {
        X--;
        Y++;
    }
    else if (X + 1 < h && Y + 1 < w && ((t[X + 1][Y + 1] >= 'A' && t[X + 1][Y + 1] <= 'Z') || (t[X + 1][Y + 1] >= '0' && t[X + 1][Y + 1] <= '9')))
    {
        X++;
        Y++;
    }
    else if (X + 1 < h && Y - 1 >= 0 && ((t[X + 1][Y - 1] >= 'A' && t[X + 1][Y - 1] <= 'Z') || (t[X + 1][Y - 1] >= '0' && t[X + 1][Y - 1] <= '9')))
    {
        X++;
        Y--;
    }
    int l = Y, p = Y;
    while (l >= 0)
    {
        if ((t[X][l] >= 'A' && t[X][l] <= 'Z') || (t[X][l] >= '0' && t[X][l] <= '9'))
        {
            l--;
        }
        else
            break;
    }
    while (p < w)
    {
        if ((t[X][p] >= 'A' && t[X][p] <= 'Z') || (t[X][p] >= '0' && t[X][p] <= '9'))
        {
            p++;
        }
        else
            break;
    }
    Y = l;
    char* c = new char[p - l];
    while (Y < p)
    {
        c[Y - l] = t[X][Y + 1];
        Y++;
    }
    c[p - l - 1] = '\0';

    return c;
}

bool haveFriends(char** t, int w, int h, int x, int y)
{
    if (x - 1 >= 0 && (t[x - 1][y] == '*' || t[x - 1][y] == '#'))
        return true;
    if (x + 1 < h && (t[x + 1][y] == '*' || t[x + 1][y] == '#'))
        return true;
    if (y - 1 >= 0 && (t[x][y - 1] == '*' || t[x][y - 1] == '#'))
        return true;
    if (y + 1 < w && (t[x][y + 1] == '*' || t[x][y + 1] == '#'))
        return true;
    return false;
}

list<hashElement>* bfs(pair<int, int> pos, char** map, int width, int height, hashmap<pair<int, int>, char*>& cityNames)
{
    if (!haveFriends(map, width, height, X, Y))
        return nullptr;

    int distance = 0;
    list<hashElement>* fr = nullptr;
    bool** vis = new bool* [height];
    for (int i = 0; i < height; i++)
    {
        vis[i] = new bool[width];
        for (int j = 0; j < width; j++)
        {
            vis[i][j] = false;
        }
    }
    
    queue<pair<pair<int, int>, int>>posDis;
    posDis.push({ pos, distance });
    vis[X][Y] = true;
    
    while (posDis.getSize() != 0)
    {
        pos = posDis.front().key;
        distance = posDis.front().value + 1;
        if (X - 1 >= 0 && (map[X - 1][Y] == '#' || map[X - 1][Y] == '*') 
            && !vis[X - 1][Y])
        {
            vis[X - 1][Y] = true;
            if (map[X - 1][Y] == '*')
                fr = fr->push({ distance, cityNames.get({ X - 1,Y }) });
            else
                posDis.push({{X - 1, Y}, distance});
        }
        if (X + 1 < height && (map[X + 1][Y] == '#' || map[X + 1][Y] == '*')
            && !vis[X + 1][Y])
        {
            vis[X + 1][Y] = true;
            if (map[X + 1][Y] == '*')
                fr = fr->push({ distance, cityNames.get({ X + 1,Y }) });
            else
                posDis.push({ {X + 1, Y}, distance });
        }
        if (Y - 1 >= 0 && (map[X][Y - 1] == '#' || map[X][Y - 1] == '*')
            && vis[X][Y - 1] != true)
        {
            vis[X][Y - 1] = true;
            if (map[X][Y - 1] == '*')
                fr = fr->push({ distance, cityNames.get({ X,Y - 1 }) });
            else
                posDis.push({ {X, Y - 1}, distance });
        }
        if (Y + 1 < width && (map[X][Y + 1] == '#' || map[X][Y + 1] == '*')
            && vis[X][Y + 1] != true)
        {
            vis[X][Y + 1] = true;
            if (map[X][Y + 1] == '*')
                fr = fr->push({ distance, cityNames.get({ X,Y + 1 }) });
            else
                posDis.push({ {X, Y + 1}, distance });
        }

        posDis.pop();
    }

    for (int i = 0; i < height; i++)
    {
        delete[]vis[i];
    }
    delete[]vis;
    return fr;
}

char* czytajString(bool fl)
{
    char* tmp = new char[10];
    int i = 1;
    if(fl)
        tmp[0] = getchar();
    tmp[0] = getchar();
    while (tmp[i - 1] != ' ')
    {
        tmp[i] = getchar();
        i++;
    }
    tmp[i - 1] = '\0';
    return tmp;
}

bool equals(char* c1, char* c2)
{
    //cout << !strcmp(c1, c2);
    bool same = true;
    int i = 0;
    while (c1[i] != '\0' || c2[i] != '\0')
        if (c1[i] != c2[i])
        {
            same = false;
            break;
        }
        else
            i++;
    return same;
}

int dijkstra_time(char* from, char* to, hashmap<char*, list<hashElement>*>& hashma, list<char*>* allCities)
{
    if (!strcmp(from, to))
        return 0;
    
    char* c = nullptr;
    hashmap<char*, pair<int, char*>> map(10); //city, distance, prev
    queue<pair<int, char*>> que; //distance, name
    
    que.push({ 0, from });
    while (allCities != nullptr)
    {
        allCities = allCities->pop_without_delete(c);
        map.put(c, { MAX, nullptr });
    }

    map.set(from, { 0, nullptr });

    while (que.getSize() != 0)
    {
        pair<int, char*> pa = que.pop();
        list<hashElement>* fr = hashma.get(pa.value);
        while (fr != nullptr)
        {
            int tmpDist = map.get(pa.value).key + fr->getElem().distance;
            list <pair< char*, pair<int, char* >> >* tmp = map.getListPtr(fr->getElem().friendName);

            if (tmpDist < tmp->DISTANCE)
            {
                tmp->set(0, { tmp->CITY_NAME, {tmpDist, pa.value}});
                que.push({ tmpDist, fr->getElem().friendName });
            }
            fr = fr->getNext();
        }
        if (!strcmp(pa.value, to))
            break;
    }

    return map.get(to).key;
}

void dijkstra_way(char* from, char* to, hashmap<char*, list<hashElement>*> hashma, list<char*>* allCities)
{
    if (!strcmp(from, to))
    {
        printf("0\n");
        return;
    }

    char* c = nullptr;
    hashmap<char*, pair<int, char*>> map(10); //city, distance, prev
    queue<pair<int, char*>> que; //distance, name

    que.push({ 0, from });
    while (allCities != nullptr)
    {
        allCities = allCities->pop_without_delete(c);
        map.put(c, { MAX, nullptr });
    }

    map.set(from, { 0, nullptr });

    while (que.getSize() != 0)
    {
        pair<int, char*> pa = que.pop();
        list<hashElement>* fr = hashma.get(pa.value);
        while (fr != nullptr)
        {
            int tmpDist = map.get(pa.value).key + fr->getElem().distance;
            list <pair< char*, pair<int, char* >> >* tmp = map.getListPtr(fr->getElem().friendName);

            if (tmpDist < tmp->DISTANCE)
            {
                tmp->set(0, { tmp->CITY_NAME, {tmpDist, pa.value} });
                que.push({ tmpDist, fr->getElem().friendName });
            }
            fr = fr->getNext();
        }
        if (!strcmp(pa.value, to))
            break;
    }

    list<char*>* head = nullptr;
    //head = head->push(to);
    printf("%d ", map.get(to).key);
    while (strcmp(from, to))
    {
        to = map.get(to).value;
        head = head->push(to);
    }

    head = head->pop(to);

    while (head != nullptr)
    {
        head = head->pop(to);
        printf("%s ", to);
    }
    printf("\n");
}
/*
if (!strcmp(from, to))
        return 0;

    char* c = nullptr;
    int distance = 0;
    hashmap<char*, pair<char*, int>> map(SIZE1);
    queue<pair<int, char*>> qu;
    list<pair<char*, pair<char*, int>>>* tmp = nullptr;
    list<pair<int, char*>>* fr = nullptr;

    qu.push({ distance, from });
    while (allCities != nullptr)
    {
        allCities = allCities->pop(c);
        map.put(c, {nullptr, MAX});
        if (!strcmp(from, c))
            qu.push({ MAX, c });
    }

    map.set(from, {nullptr, distance});

    while (qu.getSize() != 0)
    {
        pair<int, char*> par = qu.pop();
        fr = hashma.get(par.value)->getElem();
        while (fr != nullptr)
        {
            int tmpDist = map.get(par.value)->getDistane() + fr->getElem().key;
            tmp = map.get(fr->getElem().value);

            if (tmpDist < tmp->getDistane())
            {
                tmp->setDistance(tmpDist);
                tmp->setPrev(c);
                qu.push({ tmpDist, fr->getElem().value });
            }
            fr = fr->getNext();
        }
        if (!strcmp(c, to))
            break;
    }
    while (qu.getSize() != 0)
            qu.pop();

    return map.get(to)->getDistane();
*/