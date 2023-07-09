#pragma once

#include <map>
#include <iostream>
#include "Item.hpp"

class Inventory {
private:
	std::map<Item, int> items;

public:
	Inventory() {

	}

	void addItem(const Item& item, int quantity = 1) {
		auto it = items.find(item);
		if (it != items.end()) {
			it->second += quantity;
		}
		else {
			items.insert(std::make_pair(item, quantity));
		}
	}

	void displayInventory() const {
		std::cout << "Inventory:\n";
			for (const auto& pair : items) {
				const Item& item = pair.first;
				int quantity = pair.second;
				std::cout << "Item: " << item.getName() << ", Quantity: " << quantity << std::endl;
		}
	}
};