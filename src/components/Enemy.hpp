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
	std::vector<Item*> dropTable;
	bool isBoss;
	Element element;

public:
	Enemy(std::string& enemyName, float enemyDamage, float enemyMaxHealth, float enemyArmor, int enemyLevel, float enemyDropExperience, int enemyDropGold, std::vector<Item*> enemyDropTable = {}, bool enemyIsBoss = false, Element enemyElement = Element::None);
	Enemy(const char* enemyName, float enemyDamage, float enemyMaxHealth, float enemyArmor, int enemyLevel, float enemyDropExperience, int enemyDropGold, std::vector<Item*> enemyDropTable = {}, bool enemyIsBoss = false, Element enemyElement = Element::None);
	
	// Getter functions
	int getId() const;

	std::string getName() const;

	float getDamage() const;
	
	float getHealth() const;
	
	float getMaxHealth() const;
	
	float getArmor() const;
	
	int getLevel() const;
	
	float getDropExperience() const;
	
	int getDropGold() const;
	
	std::vector<Item*> getDropTable() const;
	
	bool getIsBoss() const;
	
	Element getElement() const;


	// Setter functions

	void setName(std::string newName);

	void setHealth(float newHealth);

	void setMaxHealth(float newMaxHealth);

	void setArmor(float newArmor);

	void setLevel(int newLevel);

	void setDropExperience(float newDropExperience);

	void setDropGold(int newDropGold);

	void setDropTable(std::vector<Item*> newDropTable);

	void setIsBoss(bool newIsBoss);

	void setElement(Element newElement);

	// Game related functions
	void takeDamage(float damage);
};