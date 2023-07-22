// ShopInventory.hpp
#pragma once
#include <limits>

#include "Inventory.hpp"

class ShopInventory : public Inventory {
private:
	std::map<Item*, std::pair<int, int>>& items; // pair<price, amount>
	std::map<Item*, std::pair<int, int>> itemMap; // pair<price, amount>


public:

	ShopInventory();

	std::map<Item*, std::pair<int, int>>& getItems() const;

	Item* getItem(Item* targetItem) const;
	Item* getItem(int targetItemId) const;

	void setItems(std::map<Item*, std::pair<int, int>> newItems);

	void addItem(Item* item, const int& price, const int& amount = 1);
	//void addItem(Item* item, const int& amount = 1);

	void removeItem(Item* item, const int& amount = std::numeric_limits<int>::max());


	const std::map<Item*, std::pair<int, int>>::iterator findItem(Item* itemPointer) const;

};

