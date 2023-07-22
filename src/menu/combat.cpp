#include "combat.hpp"

#include <iostream>

#include "../components/Level.hpp"

void combat() {

	IOHandler::displayCombatEnemySpawned(CombatEngine::enemy.getName());

	while (CombatEngine::isEnemyAlive() && CombatEngine::isPlayerAlive()) {
		CombatEngine::fight();
		}

		if (!CombatEngine::isEnemyAlive() && CombatEngine::isPlayerAlive()) {
			IOHandler::displayEnemyDeath();
			CombatEngine::dropEnemy();
			IOHandler::displayGold(CombatEngine::player.getGold());
			IOHandler::displayExperience(CombatEngine::player.getExperience());
		}
		else if (CombatEngine::isEnemyAlive() && !CombatEngine::isPlayerAlive()) {
			IOHandler::displayPlayerDeath();
		}
		CombatEngine::enemy = Enemy("Zombie", 5, 20, 2, 1, 3, 5);
}