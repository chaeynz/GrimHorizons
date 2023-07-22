// Player.cpp
#include "Player.hpp"

// Constructors
Player::Player(std::string& playerName) : id(++lastAssignedId),
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
Player::Player(const char* playerName) : id(++lastAssignedId),
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
std::string Player::getName() const {
		return name;
	}
float Player::getHealth() const {
		return health;
	}
float Player::getMaxHealth() const {
		return maxHealth;
	}
float Player::getDamageFactor() const {
		return damageFactor;
	}
int Player::getLevel() const {
		return level;
	}
float Player::getLevelProgress() const {
		return levelProgress;
	}
int Player::getGold() const {
		return gold;
	}
float Player::getExperience() const {
		return experience;
	}
float Player::getArmor() const {
		return armor;
	}
Inventory Player::getInventory() const {
		return inventory;
	}
Weapon* Player::getEquippedWeapon() const {
		return equippedWeapon;
	}
std::vector<PhysicalAbility*> Player::getPhysicalAbilities() const {
		return physicalAbilities;
	}
std::vector<MagicAbility*> Player::getMagicAbilities() const {
		return magicAbilities;
	}

// Setter functions
void Player::setName(std::string& newName) {
		name = newName;
	}
void Player::setHealth(float newHealth) {

	}
void Player::setMaxHealth(float newMaxHealth) {
		maxHealth = newMaxHealth;
	}
void Player::setDamageFactor(float newDamageFactor) {
		damageFactor = newDamageFactor;
	}
void Player::setLevel(int newLevel) {
		level = newLevel;
	}
void Player::setLevelProgress(float newLevelProgress) {
		levelProgress = newLevelProgress;
	}
void Player::setGold(int newGold) {
		gold = newGold;
	}
void Player::setExperience(float newExperience) {
		experience = newExperience;
	}
void Player::setArmor(float newArmor) {
		armor = newArmor;
	}
void Player::setInventory(Inventory newInventory) {
		inventory = newInventory;
	}
void Player::setEquippedWeapon(Weapon* weapon) {
		equippedWeapon = weapon;
	}
void Player::setPhysicalAbilities(std::vector<PhysicalAbility*> newPhysicalAbilities) {
		physicalAbilities = newPhysicalAbilities;
	}
void Player::setMagicAbilities(std::vector<MagicAbility*> newMagicAbilities) {
		magicAbilities = newMagicAbilities;
	}

// Game related functions
void Player::die() {
	}
void Player::takeDamage(float damage) {
		health -= damage;
		if (health <= 0) {
			health = 0;
			die();
		}
	}

void Player::equipWeapon(Weapon* targetWeapon) {
	equippedWeapon = targetWeapon;
}

void Player::addPhysicalAbility(PhysicalAbility* physicalAbility) { // changed from (const PhysicalAbility* physicalAbility)
		physicalAbilities.push_back(physicalAbility);
	}
void Player::addMagicAbility(MagicAbility* magicAbility) { // changed from (const MagicAbility* physicalAbility)
		magicAbilities.push_back(magicAbility);
	}

void Player::addItemToInventory(Item* item) {
		inventory.addItem(item, 1);
	}
void Player::addItemToInventory(Item* item, int quantity) {
		inventory.addItem(item, quantity);
	}

void Player::addGold(int gold) {
	this->gold += gold;
}
void Player::addExperience(float experience) {
	this->experience += experience;
}

void Player::removeGold(int gold) {
	this->gold -= gold;
}

void Player::removeExperience(float experience) {
	this->experience -= experience;
}
