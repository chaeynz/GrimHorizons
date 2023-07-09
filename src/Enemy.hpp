#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Element.hpp"
#include "Item.hpp"

class Enemy {
protected:
	static int lastAssignedId;

	int id;
	std::string name;
	float damage; // Missing Setters
	float maxHealth;
	float health;
	float armor;
	int level;
	float dropExperience;
	int dropGold;
	std::vector<Item> dropTable;
	bool isBoss;
	Element element;

public:
	Enemy(std::string& enemyName, float enemyDamage, float enemyMaxHealth, float enemyArmor, int enemyLevel, float enemyDropExperience, int enemyDropGold, std::vector<Item> enemyDropTable = {}, bool enemyIsBoss = false, Element enemyElement = Element::None) : id(++lastAssignedId), name(enemyName), damage(enemyDamage), maxHealth(enemyMaxHealth), health(maxHealth), armor(enemyArmor), level(enemyLevel), dropExperience(enemyDropExperience), dropGold(enemyDropGold), dropTable(enemyDropTable), isBoss(enemyIsBoss), element(enemyElement) {

	}
	Enemy(const char* enemyName, float enemyDamage, float enemyMaxHealth, float enemyArmor, int enemyLevel, float enemyDropExperience, int enemyDropGold, std::vector<Item> enemyDropTable = {}, bool enemyIsBoss = false, Element enemyElement = Element::None) : id(++lastAssignedId), name(enemyName), damage(enemyDamage), maxHealth(enemyMaxHealth), health(maxHealth), armor(enemyArmor), level(enemyLevel), dropExperience(enemyDropExperience), dropGold(enemyDropGold), dropTable(enemyDropTable), isBoss(enemyIsBoss), element(enemyElement) {

	}
	// Getters
	int getId() const {
		return id;
	}

	std::string getName() const {
		return name;
	}

	float getDamage() {
		return damage;
	}

	float getHealth() const {
		return health;
	}

	float getMaxHealth() const {
		return maxHealth;
	}

	float getArmor() const {
		return armor;
	}

	int getLevel() const {
		return level;
	}

	float getDropExperience() const {
		return dropExperience;
	}

	int getDropGold() const {
		return dropGold;
	}

	std::vector<Item> getDropTable() const {
		return dropTable;
	}

	bool getIsBoss() const {
		return isBoss;
	}

	Element getElement() const {
		return element;
	}

	// Setter functions

	void setName(std::string newName) {
		name = newName;
	}

	void setHealth(float newHealth) {
		health = newHealth;
	}

	void setMaxHealth(float newMaxHealth) {
		maxHealth = newMaxHealth;
	}

	void setArmor(float newArmor) {
		armor = newArmor;
	}

	void setLevel(int newLevel) {
		level = newLevel;
	}

	void setDropExperience(float newDropExperience) {
		dropExperience = newDropExperience;
	}

	void setDropGold(int newDropGold) {
		dropGold = newDropGold;
	}

	void setDropTable(std::vector<Item> newDropTable) {
		dropTable = newDropTable;
	}

	void setIsBoss(bool newIsBoss) {
		isBoss = newIsBoss;
	}

	void setElement(Element newElement) {
		element = newElement;
	}

	// Game related functions

	void takeDamage(float damage) {
		health -= damage;
	}
};