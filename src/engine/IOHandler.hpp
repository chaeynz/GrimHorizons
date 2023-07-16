#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "../components/Ability.hpp"
#include "../components/Inventory.hpp"
#include "../components/Item.hpp"

enum class CombatOption {
	PhysicalAbility,
	MagicAbility,
	BuffAbility,
	EquippedWeapon,
	Quit
};

class IOHandler {
public:
	static void displayPlayerDeath();

	static void displayCausedDamage(const std::string& causerName, const std::string& receiverName, const float& causedDamage, const float& receiverHealth, const float& receiverMaxHealth);

	static void displayInventory(const Inventory& inventory);

	static void displayPhysicalAbilities(const std::vector<PhysicalAbility*>& abilities);
	static void displayMagicAbilities(const std::vector<MagicAbility*>& abilities);

	static void displaySelectionPhysicalAbilities(const std::vector<PhysicalAbility*>& physicalAbilities);
	static void displaySelectionMagicAbilities(const std::vector<MagicAbility*>& magicAbilities);
	static void displaySelectionCombatOptions(const std::vector<PhysicalAbility*>& playerPhysicalAbilities, const std::vector<MagicAbility*>& playerMagicAbilities, Weapon* playerEquippedWeapon);

	static void displayNotifySelectedPhysicalAbility(const PhysicalAbility* physicalAbility);
	static void displayNotifySelectedMagicAbility(const MagicAbility* magicAbility);
	static void displayNotifySelectedEquippedWeapon(const Weapon* equippedWeapon);

	static void displayInvalidChoice();
	static void displayPromptForInput();

		// Readers

	static int readChoice();

	static PhysicalAbility* readSelectionPhysicalAbilities(const std::vector<PhysicalAbility*>& physicalAbilities);
	static MagicAbility* readSelectionMagicAbilities(const std::vector<MagicAbility*>& magicAbilities);
	
	
	static CombatOption readSelectionCombatOptions(const std::vector<PhysicalAbility*>& playerPhysicalAbilites, const std::vector<MagicAbility*>& playerMagicAbilites, Weapon* playerEquippedWeapon);
};