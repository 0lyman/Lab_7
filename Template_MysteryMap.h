#pragma once 
#include <cctype>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>     /* srand, rand */

using namespace std;

/*
This Template Class is a Map that has a key and a vector of items that are associated with it
the key can be one data type while the vector of items can be a vector of another data type(items are all the same data type)

Constructors:
MysteryMap()
MysteryMap(K key, I item)

Destructor:
~MysteryMap()

Functions:
void addItem(I item)		// adds an item at the end of the vector of items
I getRandomItem()			// returns a random item from the vector of items
I getItems(int indexNumber)	// return item from vector at indicated index Number, else returns NULL
vector<I> getAllItems()		// return the vector Items
bool findItem(I item)		// search Items to find Item. if found return indexing number of its location in the vector else return -1
void setKey(K key)			// set the value of Key
K getKey()					// return the value of Key
*/


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
	void addItem(I item)  // adds an item at the end of the vector of items
	{
		Items.push_back(item);
	}
	I getRandomItem()  // returns a random item from the vector of items
	{
		return Items[rand() % Items.size()]
	}
	vector<I> getAllItems() // return the vector Items
	{
		return Items;
	}
	I getItems(int indexNumber) // return item from vector at indicated index Number, else returns NULL
	{
		if (indexNumber < Items.size())
			return Items[indexNumber];
		else
			return NULL;
	}
	int findItem(I item) // search Items to find Item. if found return indexing number of its location in the vector else return -1
	{
		if (Items.size() != 0)
		{
			for (int x=0; x < Items.size(); x++)
			{
				if (item == Items[x])
					return x;
			}
		}
		else
			return -1;
	}
	I getAllItems() // return the vector Items
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
protected:
	K key;
	vector<I> Items;  // vector of like items assosiated with the key
};

