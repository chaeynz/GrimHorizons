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
	EquippedWeapon
};

class IOHandler {
public:
	static void displayPlayerDeath();

	static void displayCausedDamage(std::string causerName, std::string receiverName, float causedDamage, float receiverHealth, float receiverMaxHealth);

	static void displayInventory(Inventory& inventory);

	static void displayPhysicalAbilities(const std::vector<PhysicalAbility*>& abilities);
	static void displayMagicAbilities(const std::vector<MagicAbility*>& abilities);

	static void displaySelectionPhysicalAbilities(const std::vector<PhysicalAbility*>& physicalAbilities);
	static void displaySelectionMagicAbilities(const std::vector<MagicAbility*>& magicAbilities);
	static void displaySelectionCombatOptions(std::vector<PhysicalAbility*> playerPhysicalAbilities, std::vector<MagicAbility*> playerMagicAbilities, Weapon* playerEquippedWeapon);


	static void displayInvalidChoice();

		// Readers

	static PhysicalAbility* readSelectionPhysicalAbilities(const std::vector<PhysicalAbility*>& physicalAbilities);
	static MagicAbility* readSelectionMagicAbilities(const std::vector<MagicAbility*>& magicAbilities);
	
	
	static CombatOption readSelectionCombatOptions(std::vector<PhysicalAbility*> playerPhysicalAbilites, std::vector<MagicAbility*> playerMagicAbilites, Weapon* playerEquippedWeapon);

};