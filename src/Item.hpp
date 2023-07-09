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
	bool operator<(const Item& other) const {
		return id < other.id;
	}
	// Constructor
	// Hier werden die Strings mit Referenzen angesprochen, um unnötige Kopien der String im Memory zu verhindern
	Item(const std::string& itemName, const std::string& itemDescription, const Rarity itemRarity, const int itemValue, const int itemRequiredLevel, const float itemWeight) : name(itemName), description(itemDescription), rarity(itemRarity), value(itemValue), requiredLevel(itemRequiredLevel), weight(itemWeight) {
		id = lastAssignedId + 1;
		lastAssignedId++;
	}

	// Getter functions
	int getId() {
		return id;
	}

	std::string getName() const {
		return name;
	}

	std::string getDescription() const {
		return description;
	}

	Rarity getRarity() const {
		return rarity;
	}

	int getValue() const {
		return value;
	}

	int getRequiredLevel() const {
		return requiredLevel;
	}

	float getWeight() const {
		return weight;
	}


	// Other functions
	void displayItem() const {
		std::cout << "Item: " << name << std::endl;
		std::cout << "Description: " << description << std::endl;
		// TODO: Add the attribute string rarityString to the class Item
		std::cout << "Rarity: " << static_cast<int>(rarity) << std::endl;
		std::cout << "Value: " << value << std::endl;
		std::cout << "Required Level: " << requiredLevel << std::endl;
		std::cout << "Weight: " << weight << std::endl;
	}

};

class Weapon : public Item {
private:	
	float damage;
	float durability;
	Element element; // Getter&Setter missing

public:
	/// <summary>
	/// Weapon constructor ;
	/// Auto-ID Assignment ;
	/// Thorough manual attribute initialization ;
	/// </summary>
	/// <param name="itemName"></param>
	/// <param name="itemDescription"></param>
	/// <param name="itemRarity"></param>
	/// <param name="itemValue"></param>
	/// <param name="itemRequiredLevel"></param>
	/// <param name="itemWeight"></param>
	/// <param name="weaponDamage"></param>
	/// <param name="weaponDurability"></param>
	Weapon(const std::string& itemName, const std::string& itemDescription, const Rarity itemRarity, const int itemValue, const int itemRequiredLevel, const float itemWeight, const float weaponDamage, Element weaponElement = Element::None) : Item(itemName, itemDescription, itemRarity, itemValue, itemRequiredLevel, itemWeight), damage(weaponDamage), element(weaponElement) {
	
	}

	/// <summary>
	/// Weapon constructor ;
	/// Auto-ID Assignment ;
	/// Thorough manual attribute initialization ;
	/// Manual durability initialization ;
	/// </summary>
	/// <param name="itemName"></param>
	/// <param name="itemDescription"></param>
	/// <param name="itemRarity"></param>
	/// <param name="itemValue"></param>
	/// <param name="itemRequiredLevel"></param>
	/// <param name="itemWeight"></param>
	/// <param name="weaponDamage"></param>
	/// <param name="weaponDurability"></param>
	Weapon(const std::string& itemName, const std::string& itemDescription, const Rarity itemRarity, const int itemValue, const int itemRequiredLevel, const float itemWeight, const float weaponDamage, const float weaponDurability) : Item(itemName, itemDescription, itemRarity, itemValue, itemRequiredLevel, itemWeight), damage(weaponDamage), durability(weaponDurability) {

	}

	float getDamage() const {
		return damage;
	}

	float getDurability() const {
		return durability;
	}

	// Other member functions
	void displayItem() const {
		std::cout << "Item: " << name << std::endl;
		std::cout << "Description: " << description << std::endl;
		std::cout << "Damage: " << damage << std::endl;
		// TODO: Add the attribute string rarityString to the class Item
		std::cout << "Rarity: " << static_cast<int>(rarity) << std::endl;
		std::cout << "Value: " << value << std::endl;
		std::cout << "Required Level: " << requiredLevel << std::endl;
		std::cout << "Weight: " << weight << std::endl;
	}
};