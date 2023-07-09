#pragma once

#include <algorithm>
#include <iostream>

#include "Enemy.hpp"
#include "Player.hpp"
#include "Ability.hpp"

#include "gameAbilities.hpp"

class CombatEngine {
public:
	static Player player;
	static Enemy enemy;

	static std::vector<Ability> abilities;
	static std::vector<PhysicalAbility> physicalAbilities;
	static std::vector<MagicAbility> magicAbilities;

	// Game related functions
	static bool isEnemyAlive() {
		if (enemy.getHealth() > 0) {
			return true;
		}
		else if (enemy.getHealth() == 0) {
			return false;
		}
		else {
			std::cout << "Error: Enemy HP is below 0\n";
			return false;
		}
	}
	
	static bool isPlayerAlive() {
		if (player.getHealth() > 0) {
			return true;
		}
		else if (player.getHealth() == 0) {
			return false;
		}
		else {
			std::cout << "Error: Player HP is below 0\n";
			return false;
		}
	}

	static void attackPlayer() {
	//	player.takeDamage(calculateEnemyDamage());
	}

	// attack with Weapon
	static void attackEnemy() {
		
	}

	// Attack with physical ability
	static void attackEnemy(const PhysicalAbility& physicalAbility) {
		float damage = calculatePlayerDamage(physicalAbility);
		enemy.takeDamage(damage);

		std::cout << player.getName() << " caused " << damage << " damage to " << enemy.getName() << std::endl;
	}
	
	// Attack with magic ability
	static void attackEnemy(const MagicAbility& magicAbility) {

	}

	static void distributeExperience() {

	}

	static void distributeGold() {

	}

	static void distributeLoot() {
		if (enemy.getHealth() == 0) {

		}
		else if (enemy.getHealth() < 0) {
			std::cout << "Attenzione! Health below 0";
		}
	}

	static PhysicalAbility& selectPhysicalAbility() {
		player.displayPhysicalAbilities();
		std::cout << "Select an ability:\n";
		int choice;
		std::cin >> choice;
		if (choice >= 1 && choice <= static_cast<int>(player.getPhysicalAbilities().size())) {
			return player.getPhysicalAbilities()[choice - 1];
		}
		else {
			std::cout << "Invalid choice. Please try again";
			return selectPhysicalAbility();
		}
	}

	static MagicAbility& selectMagicAbility() {
		player.displayMagicAbilities();
		std::cout << "Select an ability:\n";
		int choice;
		std::cin >> choice;
		if (choice >= 1 && choice <= player.getMagicAbilities().size()) {
			return player.getMagicAbilities()[choice - 1];
		}
		else {
			std::cout << "Invalid choice. Please try again\n";
			return selectMagicAbility();
		}
	}

	// Damage when player attacking enemy
	static float calculatePlayerDamage(const PhysicalAbility& physicalAbility) {
		// Float that get the effective damage multiplier caused by damage deduction of enemy armor
		float damageMultiplier = static_cast<float>(1.0) - (enemy.getArmor() / static_cast<float>(100.0));
		// Float for the damage that is effectively caused to the enemy
		float effectiveDamage = player.getDamageFactor() * physicalAbility.getDamage() * damageMultiplier;

		float finalDamage = std::min(effectiveDamage, player.getHealth());
		return finalDamage;
	}

	static float calculatePlayerDamage() {
		// Float that get the effective damage multiplier caused by damage deduction of enemy armor
		float damageMultiplier = static_cast<float>(1.0) - enemy.getArmor() / static_cast<float>(100.0);
		// Float for the damage that is effectively caused to the enemy
		float effectiveDamage;
		try
		{
			effectiveDamage = player.getDamageFactor() * player.getEquippedWeapon()->getDamage() * damageMultiplier;
		}
		catch (const std::runtime_error& e)
		{
			std::cout << "Error: No Weapon is equipped (std::runtime_error)\n";
			return 0;
		}

		float finalDamage = std::min(effectiveDamage, player.getHealth());

		return finalDamage;
	}


	// Damage when enemy attacking player
	static float calculateEnemyDamage() {
		float damageMultiplier = static_cast<float>(1) - player.getArmor() / static_cast<float>(100);
		float effectiveDamage = enemy.getDamage() * damageMultiplier;

		if (effectiveDamage < 0) {
			effectiveDamage = 0;
		}

		// If damage is higher than
		float finalDamage = std::min(effectiveDamage, player.getHealth());

		return finalDamage;
	}
};