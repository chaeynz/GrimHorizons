#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "../components/Ability.hpp"
#include "../components/Inventory.hpp"
#include "../components/Item.hpp"
#include "../components/ShopInventory.hpp"

enum class CombatOption {
	PhysicalAbility,
	MagicAbility,
	BuffAbility,
	EquippedWeapon,
	Quit
};

enum class MainmenuOption {
	Combat,
	Shop,
	Inventory,
	AbilityTree,
	Credit,
	Quit
};

class IOHandler {
public:
	static void displayPlayerDeath();
	static void displayEnemyDeath();

	static void displayCausedDamage(const std::string& causerName, const std::string& receiverName, const float& causedDamage, const float& receiverHealth, const float& receiverMaxHealth);

	static void displayGold(const int& playerGold);
	static void displayExperience(const float& playerExperience);

	static void displayInventory(const Inventory& inventory);
	static void displayShopInventory(const std::map<Item*, std::pair<int, int>>& items);

	static void displayPhysicalAbilities(const std::vector<PhysicalAbility*>& abilities);
	static void displayMagicAbilities(const std::vector<MagicAbility*>& abilities);

	static void displaySelectionShopInventory(const std::map<Item*, std::pair<int, int>>& items);

	static void displaySelectionPhysicalAbilities(const std::vector<PhysicalAbility*>& physicalAbilities);
	static void displaySelectionMagicAbilities(const std::vector<MagicAbility*>& magicAbilities);
	static void displaySelectionCombatOptions(const std::vector<PhysicalAbility*>& playerPhysicalAbilities, const std::vector<MagicAbility*>& playerMagicAbilities, Weapon* playerEquippedWeapon);
	static void displaySelectionMainmenuOptions();

	static void displayNotifySelectedPhysicalAbility(const PhysicalAbility* physicalAbility);
	static void displayNotifySelectedMagicAbility(const MagicAbility* magicAbility);
	static void displayNotifySelectedEquippedWeapon(const Weapon* equippedWeapon);

	static void displayInvalidChoice();
	static void displayPromptForInput();

		// Readers

	static int readChoice();

	static Item* readSelectionShopInventory(const ShopInventory& shop);

	static PhysicalAbility* readSelectionPhysicalAbilities(const std::vector<PhysicalAbility*>& physicalAbilities);
	static MagicAbility* readSelectionMagicAbilities(const std::vector<MagicAbility*>& magicAbilities);
	
	
	static CombatOption readSelectionCombatOptions(const std::vector<PhysicalAbility*>& playerPhysicalAbilites, const std::vector<MagicAbility*>& playerMagicAbilites, Weapon* playerEquippedWeapon);
	static MainmenuOption readSelectionMainmenuOptions();
};