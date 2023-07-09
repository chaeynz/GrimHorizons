#pragma once

#include <iostream>
#include <string>
#include "Rarity.hpp"
#include "Element.hpp"

class Item {
protected:
	int id;
	std::string name;
	std::string description;
	Rarity rarity;
	int value;
	int requiredLevel;
	float weight;
	
	static int lastAssignedId;

public:
	bool operator<(const Item& other) const;

	Item(const std::string& itemName, const std::string& itemDescription, const Rarity itemRarity, const int itemValue, const int itemRequiredLevel, const float itemWeight);

	int getId();
	std::string getName() const;
	std::string getDescription() const;
	Rarity getRarity() const;
	int getValue() const;
	int getRequiredLevel() const;
	float getWeight() const;

	void displayItem() const;

};

class Weapon : public Item {
private:	
	float damage;
	float durability;
	Element element; // Getter&Setter missing

public:
	Weapon(const std::string& itemName, const std::string& itemDescription, const Rarity itemRarity, const int itemValue, const int itemRequiredLevel, const float itemWeight, const float weaponDamage, Element weaponElement = Element::None);
	Weapon(const std::string& itemName, const std::string& itemDescription, const Rarity itemRarity, const int itemValue, const int itemRequiredLevel, const float itemWeight, const float weaponDamage, const float weaponDurability);

	float getDamage() const;
	float getDurability() const;

	void displayItem() const;
};