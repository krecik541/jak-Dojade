#include"funkcje.h"


#define X pos.x
#define Y pos.y

using namespace std;

char* getCityName(int i, int j, char** t, int w, int h)
{
    if (i - 1 >= 0 && ((t[i - 1][j] >= 'A' && t[i - 1][j] <= 'Z') || (t[i - 1][j] >= '0' && t[i - 1][j] <= '9')))
        i--;
    else if (i + 1 < h && ((t[i + 1][j] >= 'A' && t[i + 1][j] <= 'Z') || (t[i + 1][j] >= '0' && t[i + 1][j] <= '9')))
        i++;
    else if (j - 1 >= 0 && ((t[i][j - 1] >= 'A' && t[i][j - 1] <= 'Z') || (t[i][j - 1] >= '0' && t[i][j - 1] <= '9')))
        j--;
    else if (j + 1 < w && ((t[i][j + 1] >= 'A' && t[i][j + 1] <= 'Z') || (t[i][j + 1] >= '0' && t[i][j + 1] <= '9')))
        j++;
    else if (i - 1 >= 0 && j - 1 >= 0 && ((t[i - 1][j - 1] >= 'A' && t[i - 1][j - 1] <= 'Z') || (t[i - 1][j - 1] >= '0' && t[i - 1][j - 1] <= '9')))
    {
        i--;
        j--;
    }
    else if (i - 1 >= 0 && j + 1 < w && ((t[i - 1][j + 1] >= 'A' && t[i - 1][j + 1] <= 'Z') || (t[i - 1][j + 1] >= '0' && t[i - 1][j + 1] <= '9')))
    {
        i--;
        j++;
    }
    else if (i + 1 < h && j + 1 < w && ((t[i + 1][j + 1] >= 'A' && t[i + 1][j + 1] <= 'Z') || (t[i + 1][j + 1] >= '0' && t[i + 1][j + 1] <= '9')))
    {
        i++;
        j++;
    }
    else if (i + 1 < h && j - 1 >= 0 && ((t[i + 1][j - 1] >= 'A' && t[i + 1][j - 1] <= 'Z') || (t[i + 1][j - 1] >= '0' && t[i + 1][j - 1] <= '9')))
    {
        i++;
        j--;
    }
    int l = j, p = j;
    while (l >= 0)
    {
        if ((t[i][l] >= 'A' && t[i][l] <= 'Z') || (t[i][l] >= '0' && t[i][l] <= '9'))
        {
            l--;
        }
        else
            break;
    }
    while (p < w)
    {
        if ((t[i][p] >= 'A' && t[i][p] <= 'Z') || (t[i][p] >= '0' && t[i][p] <= '9'))
        {
            p++;
        }
        else
            break;
    }
    j = l;
    char* c = new char[p - l];
    while (j < p)
    {
        c[j - l] = t[i][j + 1];
        j++;
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

friends_list* bfs(Para pos, char** t, int w, int h, Hashmap_CityNames& names)
{
    if (!haveFriends(t, w, h, X, Y))
        return nullptr;
    int distance = 0;
    friends_list* fr = nullptr;
    bool** vis = new bool* [h];
    for (int i = 0; i < h; i++)
    {
        vis[i] = new bool[w];
        for (int j = 0; j < w; j++)
        {
            vis[i][j] = false;
        }
    }
    queue_bfs* tail = nullptr;
    tail = tail->push(pos, distance);
    vis[pos.x][pos.y] = true;
    queue_bfs* head = tail;
    while (head != nullptr)
    {
        distance++;
        if (X - 1 >= 0 && (t[X - 1][Y] == '#' || t[X - 1][Y] == '*'))
            if (vis[X - 1][Y] != true)
            {
                vis[X - 1][Y] = true;
                if (t[X - 1][Y] == '*')
                    fr = fr->push(distance, names.get({ X - 1,Y }));
                else
                    tail = tail->push({ X - 1,Y }, distance);
            }
        if (X + 1 < h && (t[X + 1][Y] == '#' || t[X + 1][Y] == '*'))
            if (vis[X + 1][Y] != true)
            {
                vis[X + 1][Y] = true;
                if (t[X + 1][Y] == '*')
                    fr = fr->push(distance, names.get({ X + 1,Y }));
                else
                    tail = tail->push({ X + 1,Y }, distance);
            }
        if (Y - 1 >= 0 && (t[X][Y - 1] == '#' || t[X][Y - 1] == '*'))
            if (vis[X][Y - 1] != true)
            {
                vis[X][Y - 1] = true;
                if (t[X][Y - 1] == '*')
                    fr = fr->push(distance, names.get({ X,Y - 1 }));
                else
                    tail = tail->push({ X,Y - 1 }, distance);
            }
        if (Y + 1 < w && (t[X][Y + 1] == '#' || t[X][Y + 1] == '*'))
            if (vis[X][Y + 1] != true)
            {
                vis[X][Y + 1] = true;
                if (t[X][Y + 1] == '*')
                    fr = fr->push(distance, names.get({ X,Y + 1 }));
                else
                    tail = tail->push({ X,Y + 1 }, distance);
            }

        head = head->pop(pos, distance);
    }

    for (int i = 0; i < h; i++)
    {
        delete[]vis[i];
    }
    delete[]vis;
    return fr;
}

char* czytajString()
{
    char* tmp = new char[10];
    int i = 1;
    tmp[0] = getchar();
    while (tmp[i - 1] != ' ')
    {
        tmp[i] = getchar();
        i++;
    }
    tmp[i - 1] = '\0';
    return tmp;
}

char* czytajString1()
{
    char* tmp = new char[10];
    int i = 1;
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

bool sameString(char* c1, char* c2)
{
    cout << !strcmp(c1, c2);
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

int dijkstra_time(char* from, char* to, Hashmap* hashmap, list_cityName* allCities)
{
    if (!strcmp(from, to))
        return 0;
    char* c = nullptr;
    int distance = 0;
    Hashmap_Dijkstra map(SIZE1);
    list_city_distance* list = nullptr;
    list_Dijkstra* tmp = nullptr;
    friends_list* fr = nullptr;
    list = list->push_end(distance, from);
    while (allCities != nullptr)
    {
        allCities = allCities->pop_front(&c);
        map.put(c);
        /*if (!sameString(from, c))
                list = list->push_end(MAX, c);*/
    }
    map.get(from)->setDistance(distance);
    while (list != nullptr)
    {
        list = list->pop_front(&c, distance);
        fr = hashmap->get(c);
        while (fr != nullptr)
        {
            int tmpDist = map.get(c)->getDistane() + fr->get_dis();
            tmp = map.get(fr->getFriend());

            if (tmpDist < tmp->getDistane())
            {
                tmp->setDistance(tmpDist);
                tmp->setPrev(c);
                list = list->push_end(tmpDist, fr->getFriend());
            }
            fr = fr->get_at_pos(1);
        }
        if (!strcmp(c, to))
            break;
    }
    /*while (list != nullptr)
            list = list->pop_front(&c, distance);*/

    return map.get(to)->getDistane();
}

void dijkstra_way(char* from, char* to, Hashmap* hashmap, list_cityName* allCities)
{
    if (!strcmp(from, to))
    {
        cout << 0 << endl;
        return;
    }
    char* c = nullptr;
    int distance = 0;
    Hashmap_Dijkstra map(SIZE1);
    list_city_distance* list = nullptr;
    list_Dijkstra* tmp = nullptr;
    friends_list* fr = nullptr;
    list = list->push_end(distance, from);
    while (allCities != nullptr)
    {
        allCities = allCities->pop_front(&c);
        map.put(c);
        /*if (!sameString(from, c))
                list = list->push_end(MAX, c);*/
    }
    map.get(from)->setDistance(distance);
    while (list != nullptr)
    {
        list = list->pop_front(&c, distance);
        fr = hashmap->get(c);
        while (fr != nullptr)
        {
            int tmpDist = map.get(c)->getDistane() + fr->get_dis();
            tmp = map.get(fr->getFriend());

            if (tmpDist < tmp->getDistane())
            {
                tmp->setDistance(tmpDist);
                tmp->setPrev(c);
                list = list->push_end(tmpDist, fr->getFriend());
            }
            fr = fr->get_at_pos(1);
        }
        if (!strcmp(c, to))
            break;
    }
    list_cityName* head = nullptr;
    head = head->push_front(to);
    cout << map.get(to)->getDistane() << " ";
    while (!!strcmp(from, to))
    {
        to = map.get(to)->getPrev();
        head = head->push_front(to);
    }
    head->write();
    cout << endl;
    /*while (list != nullptr)
            list = list->pop_front(&c, distance);*/

    return;
}