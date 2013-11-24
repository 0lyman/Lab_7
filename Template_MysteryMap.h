#pragma once
#include <iostream>
#include <string>
#include <sstream>  
#include <cctype>
#include <vector>
#include <time.h>
#include <stdlib.h>     /* srand, rand */

using namespace std;

template <class K, class I> class MysteryMap
{
public:
	MysteryMap() {}
	MysteryMap(K key, I item)
	{
		srand(time(NULL));
		Key = key;
		Items.push_back(item);
	}
	~MysteryMap(){}
	void addItem(I item)
	{
		Items.push_back(item);
	}
	I getRandomItem()
	{
		return Items[rand() % Items.size()]
	}
	vector<I> getAllItems() // return the vector Items
	{
		return Items;
	}
	void setKey(K key) // set the value of Key
	{
		Key = key;
	}
	K getKey() // return the value of Key
	{
		return Key;
	}
	bool findItem(I item) // search Items to find Item. if found return true else return false
	{
		if (Items.size() != 0)
		{
			for (int x=0; x < Items.size(); x++)
			{
				if (item == Items[x])
					return true;
			}
		}
		else
			return false;
	}
protected:
	K key;
	vector<I> Items;  // vector of like items assosiated with the key
};

