#pragma once
#include "pair.h"
#include "list.h"

struct cityNamesList {
	char* cityName;
	pair<int, int> position;
};

struct friends {
	int distance;
	char* friendName;
};

struct hashElement {
	int distance;
	char* friendName;
};