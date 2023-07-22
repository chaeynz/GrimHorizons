#include "Item.hpp"

	bool Item::operator<(const Item& other) const {
		return id < other.id;
	}
	bool Item::operator==(const Item& other) const {
		return id == other.id; // Compare based on the ID
	}

	Item::~Item() {

	}


	// Constructor
	Item::Item(const std::string& itemName, const std::string& itemDescription, const Rarity itemRarity, const int itemValue, const int itemRequiredLevel, const float itemWeight) : name(itemName), description(itemDescription), rarity(itemRarity), value(itemValue), requiredLevel(itemRequiredLevel), weight(itemWeight) {
		id = lastAssignedId + 1;
		lastAssignedId++;
	}
	
	int Item::getId() {
		return id;
	}
	std::string Item::getName() const {
		return name;
	}
	std::string Item::getDescription() const {
		return description;
	}
	Rarity Item::getRarity() const {
		return rarity;
	}
	int Item::getValue() const {
		return value;
	}
	int Item::getRequiredLevel() const {
		return requiredLevel;
	}
	float Item::getWeight() const {
		return weight;
	}
	
	void Item::displayItem() const {
		std::cout << "Item: " << name << std::endl;
		std::cout << "Description: " << description << std::endl;
		// TODO: Add the attribute string rarityString to the class Item
		std::cout << "Rarity: " << static_cast<int>(rarity) << std::endl;
		std::cout << "Value: " << value << std::endl;
		std::cout << "Required Level: " << requiredLevel << std::endl;
		std::cout << "Weight: " << weight << std::endl;
	}
	
	
	
	Weapon::Weapon(const std::string& itemName, const std::string& itemDescription, const Rarity itemRarity, const int itemValue, const int itemRequiredLevel, const float itemWeight, const float weaponDamage, Element weaponElement) : Item(itemName, itemDescription, itemRarity, itemValue, itemRequiredLevel, itemWeight), damage(weaponDamage), element(weaponElement) {
		}
	Weapon::Weapon(const std::string& itemName, const std::string& itemDescription, const Rarity itemRarity, const int itemValue, const int itemRequiredLevel, const float itemWeight, const float weaponDamage, const float weaponDurability) : Item(itemName, itemDescription, itemRarity, itemValue, itemRequiredLevel, itemWeight), damage(weaponDamage), durability(weaponDurability) {
		}

	float Weapon::getDamage() const {
		return damage;
	}
	float Weapon::getDurability() const {
		return durability;
	}

	// Other member functions
	void Weapon::displayItem() const {
		std::cout << "Item: " << name << std::endl;
		std::cout << "Description: " << description << std::endl;
		std::cout << "Damage: " << damage << std::endl;
		// TODO: Add the attribute string rarityString to the class Item
		std::cout << "Rarity: " << static_cast<int>(rarity) << std::endl;
		std::cout << "Value: " << value << std::endl;
		std::cout << "Required Level: " << requiredLevel << std::endl;
		std::cout << "Weight: " << weight << std::endl;
	}