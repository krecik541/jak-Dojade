#pragma once
#include <cstdio>
#include <type_traits>

template<typename K, typename V>
struct pair {
	K key;
	V value;
	pair();
	pair(K key, V value);
	int hash();
	template<typename X, typename Y>
	friend bool operator==(pair<X, Y>& par1, pair<X, Y>& par2);
	template<typename X, typename Y>
	friend bool operator!=(pair<X, Y>& par1, pair<X, Y>& par2);
};

template<typename K, typename V>
inline pair<K, V>::pair()
{
	
}

template<typename K, typename V>
inline pair<K, V>::pair(K key, V value)
{
	this->key = key;
	this->value = value;
}

template<typename K, typename V>
inline int pair<K, V>::hash()
{
	try 
	{
		return (int)key + (int)value;
	}
	catch (int err)
	{
		printf_s("Error: %d\n", err);
	}
}

template<typename X, typename Y>
inline bool operator==(pair<X, Y>& par1, pair<X, Y>& par2)
{
	return par1.key == par2.key && par1.value == par2.value;
}

template<typename X, typename Y>
inline bool operator!=(pair<X, Y>& par1, pair<X, Y>& par2)
{
	return !(par1 == par2);
}
