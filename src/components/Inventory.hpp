#pragma once

#include <map>
#include <iostream>
#include "Item.hpp"

class Inventory {
private:
	std::map<Item*, int> items;

public:
	Inventory();

	std::map<Item*, int> getItems() const;

	std::map<Item*, int>::iterator findItem(Item* itemPointer);

	void addItem(Item* targetItem, const int quantity = 1);
	void removeItem(Item* targetItem, const int quantity = 1);
};