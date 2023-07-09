#pragma once

#include <string>
#include <map>
#include <vector>
#include "Item.hpp"
#include "Ability.hpp"
#include "Inventory.hpp"

#include "gameAbilities.hpp"

class Player {
private:
	static int lastAssignedId;
	int id;
	std::string name;
	float maxHealth;
	float health;
	float damageFactor;
	int level;
	float levelProgress;
	int gold;
	float experience;
	float armor;
	Inventory inventory;
	Weapon* equippedWeapon;
	std::vector<PhysicalAbility*> physicalAbilities;
	std::vector<MagicAbility*> magicAbilities;

public:
	/// <summary>
	/// Player constructor with auto-id assignment
	/// </summary>
	/// <param name="playerName"></param>
	Player(std::string& playerName) : id(++lastAssignedId),
		name(playerName),
		maxHealth(100),
		health(maxHealth),
		damageFactor(1),
		level(1),
		levelProgress(0),
		gold(0),
		experience(0),
		armor(1),
		inventory(),
		equippedWeapon(nullptr),
		physicalAbilities({boxing}),
		magicAbilities()
	{
		physicalAbilities.push_back(boxing);
	}

	Player(const char* playerName) : id(++lastAssignedId),
		name(playerName),
		maxHealth(100),
		health(maxHealth),
		damageFactor(1),
		level(1),
		levelProgress(0),
		gold(0),
		experience(0),
		armor(1),
		inventory(),
		equippedWeapon(nullptr),
		physicalAbilities({ boxing }),
		magicAbilities()
	{
		// Nothing needed
	}

	// Getter functions
	std::string getName() const {
		return name;
	}

	float getHealth() const {
		return health;
	}

	float getMaxHealth() const {
		return maxHealth;
	}

	float getDamageFactor() const {
		return damageFactor;
	}

	int getLevel() const {
		return level;
	}

	float getLevelProgress() const {
		return levelProgress;
	}

	int getGold() const {
		return gold;
	}

	float getExperience() const {
		return experience;
	}

	float getArmor() const {
		return armor;
	}

	Inventory getInventory() const {
		return inventory;
	}

	Weapon* getEquippedWeapon() const {
		return equippedWeapon;
	}

	std::vector<PhysicalAbility*> getPhysicalAbilities() const {
		return physicalAbilities;
	}

	std::vector<MagicAbility*> getMagicAbilities() const {
		return magicAbilities;
	}

	// Setter functions
	void setName(std::string& newName) {
		name = newName;
	}

	void setHealth(float newHealth) {

	}

	void setMaxHealth(float newMaxHealth = 100) {
		maxHealth = newMaxHealth;
	}

	void setDamageFactor(float newDamageFactor = 1) {
		damageFactor = newDamageFactor;
	}

	void setLevel(int newLevel = 1) {
		level = newLevel;
	}

	void setLevelProgress(float newLevelProgress = 0) {
		levelProgress = newLevelProgress;
	}
	
	void setGold(int newGold) {
		gold = newGold;
	}

	void setExperience(float newExperience) {
		experience = newExperience;
	}

	void setArmor(float newArmor) {
		armor = newArmor;
	}

	void setInventory(Inventory newInventory) {
		inventory = newInventory;
	}

	void setEquippedWeapon(Weapon* weapon) {
		equippedWeapon = weapon;
	}

	void setPhysicalAbilities(std::vector<PhysicalAbility*> newPhysicalAbilities) {
		physicalAbilities = newPhysicalAbilities;
	}

	void setMagicAbilities(std::vector<MagicAbility*> newMagicAbilities) {
		magicAbilities = newMagicAbilities;
	}

	// Game related functions
	void die() {
		std::cout << "Better luck next time!\n";
	}

	void takeDamage(float damage) {
		health -= damage;
		if (health <= 0) {
			health = 0;
			std::cout << "You have been defeated!\n";
			die();
		}
	}
	
	void addPhysicalAbility(const PhysicalAbility* physicalAbility) {
		physicalAbilities.push_back(physicalAbility);
	}

	void addMagicAbility(const MagicAbility& magicAbility) {
		magicAbilities.push_back(magicAbility);
	}

	void addItemToInventory(const Item& item) {
		inventory.addItem(item, 1);
	}

	void addItemToInventory(const Item& item, int quantity) {
		inventory.addItem(item, quantity);
	}

	void displayPhysicalAbilities() const {
		for (size_t i = 0; i < physicalAbilities.size(); ++i) {
			std::cout << i + 1 << ". " << physicalAbilities[i].getName() << std::endl;
		}
	}
	
	void displayMagicAbilities() const {
		for (size_t i; i < magicAbilities.size(); ++i) {
			std::cout << i << ". " << magicAbilities[i].getName() << std::endl;
		}
	}
};