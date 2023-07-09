#include <iostream>

#include "CombatEngine.hpp"

#include "Player.hpp"
#include "Enemy.hpp"

#include "AbilityUtils.hpp"

void combat() {

	std::cout << CombatEngine::enemy.getName() << " appeared!\n";

	while (CombatEngine::isEnemyAlive() && CombatEngine::isPlayerAlive()) {
		CombatEngine::attackEnemy(CombatEngine::selectPhysicalAbility());
	}
}