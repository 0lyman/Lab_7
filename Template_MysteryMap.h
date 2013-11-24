#pragma once
#include <iostream>
#include <string>
#include <sstream>  
#include <cctype>
#include <vector>

using namespace std;

template <class K, class I> class MysteryMap
{
public:
	MysteryMap()
	{

	}
	MysteryMap(K Key)
	{

	}
//	MysteryMap(K Key, I Item);
	~MysteryMap()
	{

	}
	void addItem(I Item)
	{

	}
	I getItem()
	{

	}
	I getRandomItem()
	{

	}
	vector<I> getAllItems()
	{

	}
	K setKey(K Key)
	{

	}
	K getKey()
	{

	}
protected:
	K key;
	vector<I> Items;  // vector of like items assosiated with the key
};

