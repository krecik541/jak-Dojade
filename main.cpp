// adding [] to hashmap
// getting rid of (SIZE) from hashmap


#include "headers/list.h"
#include "headers/pair.h"
#include "headers/funkcje.h"
#include "headers/hashmap.h"
#include "headers/structs.h"
#include "headers/queue.h"
#include <cstdio>

void freeListOfStrings(list<char*>* cities) {
	while (cities != nullptr) {
		char* city;
		cities = cities->pop(city);
		delete[] city;
	}
}

void freeAdjacencyList(hashmap<char*, list<hashElement>*>& adjacencyList) {
	for (int i = 0; i < adjacencyList.getSize(); ++i) {
		list<pair<char*, list<hashElement>*>>* bucket = adjacencyList.getListPtr(nullptr);
		while (bucket != nullptr) {
			pair<char*, list<hashElement>*> entry = bucket->getElem();
			list<hashElement>* elements = entry.value;
			while (elements != nullptr) {
				hashElement elem;
				elements = elements->pop(elem);
			}
			delete entry.value;  // Free the list pointer
			bucket = bucket->getNext();
		}
	}
}

int main()
{
	int width, height;
	list<pair<int, int>>* citiesPosition = nullptr;
	hashmap<pair<int, int>, char*> cityNames(SIZE);
	hashmap<char*, list<hashElement>*> adjacencyList(SIZE);
	list<char*>* allCities = nullptr;
	
	scanf_s("%d%d", &width, &height);
	char** map = new char* [height];

	for (int i = 0; i < height; i++)
	{
		map[i] = new char[width];
		getchar();
		for (int j = 0; j < width; j++)
		{
			map[i][j] = getchar();
			if (map[i][j] == '*')
			{
				pair<int, int> position(i, j);
				citiesPosition = citiesPosition->push(position);
			}
		}
	}

	list<pair<int, int>>* tmp = citiesPosition;
	pair<int, int> pos;
	while (tmp != nullptr)
	{
		pos = tmp->getElem();
		char* c = getCityName(pos, map, width, height);
		cityNames.put(pos, c);
		tmp = tmp->getNext();
		allCities = allCities->push(c);
	}

	while (citiesPosition != nullptr)
	{
		citiesPosition = citiesPosition->pop(pos);
		char* c = cityNames.get(pos);
		adjacencyList.put(c, bfs(pos, map, width, height, cityNames));
	}
	for (int i = 0; i < height; i++)
		delete[]map[i];
	delete[]map;

	int n;
	scanf_s("%d", &n);
	int dis = 0;
	char* c1 = nullptr, * c2 = nullptr;

	for (int i = 0; i < n; i++)
	{
		c1 = czytajString();
		c2 = czytajString(false);
		scanf_s("%d", &dis);
		adjacencyList.set(c1, adjacencyList.get(c1)->push({dis, c2}));
	}

	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		c1 = czytajString();
		c2 = czytajString(false);
		scanf_s("%d", &dis);
		if (dis == 0)
			printf("%d\n", dijkstra_time(c1, c2, adjacencyList, allCities));
		else
			dijkstra_way(c1, c2, adjacencyList, allCities);
	}

	delete[]c1;
	delete[]c2;

	freeListOfStrings(allCities);
	//freeAdjacencyList(adjacencyList);

	return 0;
}