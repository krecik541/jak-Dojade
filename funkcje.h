#pragma once
#include"Para.h"
#include"friends_list.h"
#include"Hashmap_CityNames.h"
#include"Hashmap.h"
#include"list_cityName.h"
#include"queue_bfs.h"
#include"Hashmap_Dijkstra.h"
#include"list_city_distance.h"
#include<iostream>
#include<cstdio>
#include<string>

#define GORA 0
#define LEWO 1
#define PRAWO 2
#define DOL 3

#define SIZE 11699
#define SIZE1 11699
#define MAX 1000000000

char* getCityName(int i, int j, char** t, int w, int h);

bool haveFriends(char** t, int w, int h, int x, int y);

friends_list* bfs(Para pos, char** t, int w, int h, Hashmap_CityNames& names);

char* czytajString();
char* czytajString1();

bool sameString(char* c1, char* c2);

int dijkstra_time(char* from, char* to, Hashmap* hashmap, list_cityName* allCities);

void dijkstra_way(char* from, char* to, Hashmap* hashmap, list_cityName* allCities);