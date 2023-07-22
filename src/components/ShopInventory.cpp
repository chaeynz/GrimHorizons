// ShopInventory.cpp
#include "ShopInventory.hpp"

ShopInventory::ShopInventory() : items(itemMap) {
}

	std::map<Item*, std::pair<int, int>>& ShopInventory::getItems() const {
		return items;
	}

	Item* ShopInventory::getItem(Item* targetItem) const {
		return nullptr;
	}
	Item* ShopInventory::getItem(int targetItemId) const {
		return nullptr;
	}

	void ShopInventory::setItems(std::map<Item*, std::pair<int, int>> newItems) {
		items = newItems;
	}

	void ShopInventory::addItem(Item* item, const int& price, const int& quantity) {
		auto it = items.find(item);
		if (it != items.end()) {
			it->second.first = price; // defines the price
			it->second.second += quantity; // adds x amount of items
		}
		else {
			items.insert(std::make_pair(item, std::make_pair(price, quantity)));
		}
	}

	/*void ShopInventory::addItem(Item* item, const int& quantity) {
		auto it = items.find(item);
		if (it != items.end()) {
			it->second.first = it->second.first;
			it->second.second += quantity;
		}
		else {
			return;
		}
	}*/

	void ShopInventory::removeItem(Item* item, const int& amount) {
		auto it = items.find(item);
		if (it != items.end()) {
			int currentAmount = it->second.second;
			int itemsToRemove = (amount == std::numeric_limits<int>::max()) ? currentAmount : amount;

			if (itemsToRemove >= currentAmount) {
				items.erase(it);
			}
			else {
				it->second.second -= itemsToRemove;
			}
		}
	}

	const std::map<Item*, std::pair<int, int>>::iterator ShopInventory::findItem(Item* itemPointer) const {
		for (auto it = items.begin(); it != items.end(); ++it) {
			if (*(it->first) == *itemPointer) {
				return it;
			}
		}
		return items.end();
	}
