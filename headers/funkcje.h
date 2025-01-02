#pragma once
#include "pair.h"
#include "list.h"
#include "structs.h"
#include "hashmap.h"
#include <cstdio>

#define GORA 0
#define LEWO 1
#define PRAWO 2
#define DOL 3

#define SIZE1 11699
#define MAX 1000000000

template<typename K, typename V>
class hashmap;

char* getCityName(pair<int, int> pos, char** t, int w, int h);

bool haveFriends(char** t, int w, int h, int x, int y);

list<hashElement>* bfs(pair<int, int> pos, char** map, int width, int height, hashmap<pair<int, int>, char*>& cityNames);

char* czytajString(bool fl = true);

bool equals(char* c1, char* c2);

int dijkstra_time(char* from, char* to, hashmap<char*, list<hashElement>*>& hashma, list<char*>* allCities);

void dijkstra_way(char* from, char* to, hashmap<char*, list<hashElement>*> hashma, list<char*>* allCities);
