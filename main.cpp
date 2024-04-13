#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include "funkcje.h"
#include "friends_list.h"
#include"Para.h"
#include"list_city.h"
#include"list_cityName.h"
#include"Hashmap_CityNames.h"
#include"Hashmap.h"

using namespace std;

int main()
{
    Para position;
    int w, h, n;
    list_city* cities = nullptr, * tmp_cities = nullptr;
    list_cityName* allCities = nullptr;
    Hashmap hashmap(SIZE1);

    //cin >> w >> h;
    scanf("%d%d", &w, &h);
    char** t = new char* [h];

    for (int i = 0; i < h; i++)
    {
        t[i] = new char[w];
        getchar();
        for (int j = 0; j < w; j++)
        {
            t[i][j] = getchar();
            if (t[i][j] == '*')
            {
                cities = cities->push_front({ i, j });
                tmp_cities = tmp_cities->push_front({ i, j });
            }
        }
    }

    Hashmap_CityNames* names = new Hashmap_CityNames(SIZE);

    char* c = nullptr;
    while (tmp_cities != nullptr)
    {
        tmp_cities = tmp_cities->pop_front(position);
        c = getCityName(position.x, position.y, t, w, h);
        names->put(c, position);
        allCities = allCities->push_front(c);
    }

    while (cities != nullptr)
    {
        cities = cities->pop_front(position);
        c = names->get(position);
        hashmap.put(c, bfs(position, t, w, h, *names));
    }
    delete names;
    c = nullptr;
    delete[]c;
    for (int i = 0; i < h; i++)
        delete[]t[i];
    delete[]t;
    delete tmp_cities;
    delete cities;
    t = nullptr;

    //cout << "BFS ZAKONCZONY\n";

    scanf("%d", &n);
    int dis = 0;
    char* c1 = nullptr, * c2 = nullptr;
    for (int i = 0; i < n; i++)
    {
        c1 = czytajString1();
        c2 = czytajString();
        scanf("%d", &dis);
        hashmap.addOne(c1, c2, dis);
    }

    //cout << "PARSOWANIE ZAKONCZONE\n";

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        c1 = czytajString1();
        c2 = czytajString();
        scanf("%d", &dis);
        if (dis == 0)
            cout << dijkstra_time(c1, c2, &hashmap, allCities) << endl;
        else
            dijkstra_way(c1, c2, &hashmap, allCities);
    }

    delete[]c1;
    delete[]c2;

    return 0;
}