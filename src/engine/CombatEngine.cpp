// CombatEngine.cpp
#include "CombatEngine.hpp"

	// Game related functions
	bool CombatEngine::isEnemyAlive() {
		if (enemy.getHealth() > 0) {
			return true;
		}
		else if (enemy.getHealth() == 0) {
			return false;
		}
		else {
			std::cout << "Error: Enemy HP (" << enemy.getHealth() << ") is below 0\n";
			return false;
		}
	}
	bool CombatEngine::isPlayerAlive() {
		if (player.getHealth() > 0) {
			return true;
		}
		else if (player.getHealth() == 0) {
			return false;
		}
		else {
			std::cout << "Error: Player HP (" << player.getHealth() << ") is below 0\n";
			return false;
		}
	}

	void CombatEngine::fight() {
		CombatOption selectedCombatOption;
		IOHandler::displaySelectionCombatOptions(player.getPhysicalAbilities(), player.getMagicAbilities(), player.getEquippedWeapon());

		selectedCombatOption = IOHandler::readSelectionCombatOptions(player.getPhysicalAbilities(), player.getMagicAbilities(), player.getEquippedWeapon());

		if (selectedCombatOption == CombatOption::PhysicalAbility) {
			attackEnemy(IOHandler::readSelectionPhysicalAbilities(player.getPhysicalAbilities()));
		}
		else if (selectedCombatOption == CombatOption::MagicAbility) {
			attackEnemy(IOHandler::readSelectionMagicAbilities(player.getMagicAbilities()));
		}
		else if (selectedCombatOption == CombatOption::EquippedWeapon) {
			attackEnemy(player.getEquippedWeapon());
		}

	}

	void CombatEngine::attackPlayer() {
		//	player.takeDamage(calculateEnemyDamage());
	}
	void CombatEngine::attackEnemy(const Weapon* weapon) {

	}
	void CombatEngine::attackEnemy(const PhysicalAbility* physicalAbility) {
		float damage = calculatePlayerDamage(physicalAbility);
		enemy.takeDamage(damage);

		IOHandler::displayCausedDamage(player.getName(), enemy.getName(), damage, enemy.getHealth(), enemy.getMaxHealth());
	}
	void CombatEngine::attackEnemy(const MagicAbility* magicAbility) {

	}

	void CombatEngine::distributeExperience() {

	}

	void CombatEngine::distributeGold() {

	}

	void CombatEngine::distributeLoot() {
		if (enemy.getHealth() == 0) {

		}
		else if (enemy.getHealth() < 0) {
			std::cout << "Attenzione! Health below 0";
		}
	}

	PhysicalAbility* CombatEngine::selectPhysicalAbility() {
		IOHandler::displaySelectionPhysicalAbilities(player.getPhysicalAbilities());
		PhysicalAbility* readSelectPhysicalAbility = IOHandler::readSelectionPhysicalAbilities(player.getPhysicalAbilities());
		while (selectPhysicalAbility == nullptr) {
			readSelectPhysicalAbility = IOHandler::readSelectionPhysicalAbilities(player.getPhysicalAbilities());
		}
		return readSelectPhysicalAbility;
	}

	MagicAbility* CombatEngine::selectMagicAbility() {
		//IOHandler::displaySelectMagicAbilities(player.getMagicAbilities());
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

	float CombatEngine::calculatePlayerDamage(const PhysicalAbility* physicalAbility) {	
		float damageMultiplier = static_cast<float>(1.0) - (enemy.getArmor() / static_cast<float>(100.0));	// Float that get the effective damage multiplier caused by damage deduction of enemy armor
		float effectiveDamage = player.getDamageFactor() * physicalAbility->getDamage() * damageMultiplier;	// Float for the damage that is effectively caused to the enemy


		float finalDamage = std::min(effectiveDamage, enemy.getHealth());
		return finalDamage;
	}

	float CombatEngine::calculatePlayerDamage() {
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
	float CombatEngine::calculateEnemyDamage() {
		float damageMultiplier = static_cast<float>(1) - player.getArmor() / static_cast<float>(100);
		float effectiveDamage = enemy.getDamage() * damageMultiplier;
		if (effectiveDamage < 0) {
			effectiveDamage = 0;
		}

		float finalDamage = std::min(effectiveDamage, player.getHealth()); // prevents negative playerHealth later

		return finalDamage;
	}
