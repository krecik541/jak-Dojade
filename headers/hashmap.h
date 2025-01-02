#pragma once
#include <typeinfo>
#include <string.h>
#include <cstdio>
#include "list.h"
#include "pair.h"
#include "funkcje.h"

#define SIZE 10

template<typename K, typename V>
class hashmap {
private:
	int size;
	list<pair<K, V>>* elements[SIZE];
public:
	hashmap(int size);
	~hashmap();
	void put(K key, V value);
	V get(K elem);
	list<pair<K, V>>* getListPtr(K elem);
	void set(K key, V value);
	int hash(K elem);
	int getSize();
};

template<typename K, typename V>
inline hashmap<K, V>::hashmap(int size)
{
	this->size = size;
	for (int i = 0; i < size; i++)
		elements[i] = nullptr;
}

template<typename K, typename V>
inline hashmap<K, V>::~hashmap()
{
	for (int i = 0; i < size; i++)
	{
		list <pair< K, V >>* tmp, * head = elements[i];
		while (head != nullptr)
		{
			tmp = head->getNext(); 
			//delete head;
			head = tmp;
		}
	}
}

template<typename K, typename V>
inline void hashmap<K, V>::put(K key, V value)
{
	int hashcode = hash(key);
	elements[hashcode] = elements[hashcode]->push({key, value});
}

template<typename K, typename V>
inline V hashmap<K, V>::get(K key)
{
	int hashcode = hash(key);
	list<pair<K, V>>* head = elements[hashcode];
	while (head != nullptr)
	{
		pair<K, V> elem = head->getElem();
		if constexpr (std::is_same_v<K, char*>) {
			char* k = key;
			char* el = elem.key;
			if (!strcmp(k, el))
				return elem.value;
		}
		else if (key == elem.key)
			return elem.value;
		head = head->getNext();
	}
		
	if constexpr (std::is_same_v<V, pair<int, char*>>)
		return { NULL, nullptr };
	else
		return NULL;
}

template<typename K, typename V>
inline list<pair<K, V>>* hashmap<K, V>::getListPtr(K key)
{
	int hashcode = hash(key);
	list<pair<K, V>>* head = elements[hashcode];
	while (head != nullptr)
	{
		pair<K, V> elem = head->getElem();
		if constexpr (std::is_same_v<K, char*>) {
			char* k = key;
			char* el = elem.key;
			if (!strcmp(k, el))
				return head;
		}
		else if (key == elem.key)
			return head;
		head = head->getNext();
	}

	return NULL;
}

template<typename K, typename V>
inline void hashmap<K, V>::set(K key, V value)
{
	int hashcode = hash(key);
	list<pair<K, V>>* head = elements[hashcode];
	while (head != nullptr)
	{
		pair<K, V> elem = head->getElem();
		if constexpr (std::is_same_v<K, char*>) {
			char* k = key;
			char* el = elem.key;
			if (!strcmp(k, el))
			{
				if constexpr (std::is_same_v < V, list<hashElement>*>)
				{
					list<hashElement>* el = value;
					head->elem.value = value;
				}
				else if constexpr (std::is_same_v < V, pair<int, char*>>)
				{
					head->elem.value = value;
				}
				break;
			}
		}
		else if (key == elem.key)
		{
			if constexpr (std::is_same_v < V, list<hashElement>*>)
			{
				list<hashElement>* el = value;
				head->elem.value = value;
			}
			break;
		}
		head = head->getNext();
	}
}

template<typename K, typename V>
inline int hashmap<K, V>::hash(K elem)
{
	if constexpr (std::is_same_v<K, char*>) {
		char* c = elem;
		if (c != nullptr)
			if (c[1] == '\0')
				return c[0] % size;
			else if (c[2] == '\0')
				return c[0] * c[1] % size;
			else
				return c[0] * c[1] * c[2] % size;
	}
	else if constexpr (std::is_same_v<int, K>)
	{
		int x = elem;
		return x;
	}
	else
		return elem.hash() % size;	
}

template<typename K, typename V>
inline int hashmap<K, V>::getSize()
{
	return size;
}
