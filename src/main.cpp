#include "CombatEngine.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

#include "combat.hpp"

Player CombatEngine::player = Player("Kevin");
Enemy CombatEngine::enemy = Enemy("Test", 1, 1, 1, 1, 1, 1);

int main() {
	combat();
	return 0;
}