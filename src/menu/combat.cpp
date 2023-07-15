#include "combat.hpp"

#include <iostream>

void combat() {
	while (CombatEngine::isEnemyAlive() && CombatEngine::isPlayerAlive()) {
		CombatEngine::fight();
	}
}