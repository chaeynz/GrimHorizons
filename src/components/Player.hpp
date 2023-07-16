// Player.hpp
#pragma once

#include <string>
#include <map>
#include <vector>
#include "Item.hpp"
#include "Ability.hpp"
#include "Inventory.hpp"
#include "../gamedata/gameAbilities.hpp"

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
	Player(std::string& playerName);

	Player(const char* playerName);

	// Getter functions
	std::string getName() const;
	float getHealth() const;
	float getMaxHealth() const;
	float getDamageFactor() const;
	int getLevel() const;
	float getLevelProgress() const;
	int getGold() const;
	float getExperience() const;
	float getArmor() const;
	Inventory getInventory() const;
	Weapon* getEquippedWeapon() const;
	std::vector<PhysicalAbility*> getPhysicalAbilities() const;
	std::vector<MagicAbility*> getMagicAbilities() const;

	// Setter functions
	void setName(std::string& newName);
	void setHealth(float newHealth);
	void setMaxHealth(float newMaxHealth = 100);
	void setDamageFactor(float newDamageFactor = 1);
	void setLevel(int newLevel = 1);
	void setLevelProgress(float newLevelProgress = 0);
	void setGold(int newGold);
	void setExperience(float newExperience);
	void setArmor(float newArmor);
	void setInventory(Inventory newInventory);
	void setEquippedWeapon(Weapon* weapon);
	void setPhysicalAbilities(std::vector<PhysicalAbility*> newPhysicalAbilities);
	void setMagicAbilities(std::vector<MagicAbility*> newMagicAbilities);

	// Game related functions
	void die();
	void takeDamage(float damage);

	void addPhysicalAbility(PhysicalAbility* physicalAbility);
	void addMagicAbility(MagicAbility* magicAbility);

	void addItemToInventory(Item* item);
	void addItemToInventory(Item* item, int quantity);

	void addGold(int gold);
	void addExperience(float experience);

	void removeGold(int gold);
	void removeExperience(float experience);
};