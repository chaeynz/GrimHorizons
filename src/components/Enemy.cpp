#include "Enemy.hpp"

Enemy::Enemy(std::string& enemyName, float enemyDamage, float enemyMaxHealth, float enemyArmor, int enemyLevel, float enemyDropExperience, int enemyDropGold, std::vector<Item*> enemyDropTable, bool enemyIsBoss, Element enemyElement) : id(++lastAssignedId), name(enemyName), damage(enemyDamage), maxHealth(enemyMaxHealth), health(maxHealth), armor(enemyArmor), level(enemyLevel), dropExperience(enemyDropExperience), dropGold(enemyDropGold), dropTable(enemyDropTable), isBoss(enemyIsBoss), element(enemyElement) {
	}
Enemy::Enemy(const char* enemyName, float enemyDamage, float enemyMaxHealth, float enemyArmor, int enemyLevel, float enemyDropExperience, int enemyDropGold, std::vector<Item*> enemyDropTable, bool enemyIsBoss, Element enemyElement) : id(++lastAssignedId), name(enemyName), damage(enemyDamage), maxHealth(enemyMaxHealth), health(maxHealth), armor(enemyArmor), level(enemyLevel), dropExperience(enemyDropExperience), dropGold(enemyDropGold), dropTable(enemyDropTable), isBoss(enemyIsBoss), element(enemyElement) {
	}
// Getters
int Enemy::getId() const {
		return id;
	}
std::string Enemy::getName() const {
		return name;
	}
float Enemy::getDamage() const {
		return damage;
	}
float Enemy::getHealth() const {
		return health;
	}
float Enemy::getMaxHealth() const {
		return maxHealth;
	}
float Enemy::getArmor() const {
		return armor;
	}
int Enemy::getLevel() const {
		return level;
	}
float Enemy::getDropExperience() const {
		return dropExperience;
	}
int Enemy::getDropGold() const {
		return dropGold;
	}
std::vector<Item*> Enemy::getDropTable() const {
		return dropTable;
	}
bool Enemy::getIsBoss() const {
		return isBoss;
	}
Element Enemy::getElement() const {
		return element;
	}
	// Setter functions
void Enemy::setName(std::string newName) {
		name = newName;
	}
void Enemy::setHealth(float newHealth) {
		health = newHealth;
	}
void Enemy::setMaxHealth(float newMaxHealth) {
		maxHealth = newMaxHealth;
	}
void Enemy::setArmor(float newArmor) {
		armor = newArmor;
	}
void Enemy::setLevel(int newLevel) {
		level = newLevel;
	}
void Enemy::setDropExperience(float newDropExperience) {
		dropExperience = newDropExperience;
	}
void Enemy::setDropGold(int newDropGold) {
		dropGold = newDropGold;
	}
void Enemy::setDropTable(std::vector<Item*> newDropTable) {
		dropTable = newDropTable;
	}
void Enemy::setIsBoss(bool newIsBoss) {
		isBoss = newIsBoss;
	}
void Enemy::setElement(Element newElement) {
		element = newElement;
	}
	// Game related functions
void Enemy::takeDamage(float damage) {
	health -= damage;
}