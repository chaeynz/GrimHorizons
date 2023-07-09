#include "Inventory.hpp"

	Inventory::Inventory() {

	}

	std::map<Item, int> Inventory::getItems() const {
		return items;
	}

	std::map<Item, int>::iterator Inventory::findItem(Item& item) {
		return items.find(item);
	}
	std::map<Item, int>::iterator Inventory::findItem(Item* itemPointer) {
		return items.find(*itemPointer);
	}

	void Inventory::addItem(const Item& item, int quantity) {
		auto it = items.find(item);
		if (it != items.end()) {
			it->second += quantity;
		}
		else {
			items.insert(std::make_pair(item, quantity));
		}
	}