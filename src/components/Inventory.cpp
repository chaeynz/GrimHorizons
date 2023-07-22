#include "Inventory.hpp"

	Inventory::Inventory() {

	}

	std::map<Item*, int> Inventory::getItems() const {
		return items;
	}

	std::map<Item*, int>::iterator Inventory::findItem(Item* itemPointer) {
		return items.find(itemPointer);
	}

	void Inventory::addItem(Item* targetItem, const int quantity) {
		auto it = items.find(targetItem);
		if (it != items.end()) {
			it->second += quantity;
		}
		else {
			items.insert(std::make_pair(targetItem, quantity));
		}
	}
	void Inventory::removeItem(Item* targetItem, const int quantity) {
		auto it = items.find(targetItem);
		if (it != items.end()) {
			items.erase(targetItem);
		}
	}