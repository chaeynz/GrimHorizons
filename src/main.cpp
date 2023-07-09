#include "engine/CombatEngine.hpp"
#include "components/Player.hpp"
#include "components/Enemy.hpp"

#include "menu/combat.hpp"
#include "menu/shop.hpp"

Player CombatEngine::player = Player("Kevin");
Enemy CombatEngine::enemy = Enemy("Zombie", 5, 20, 2, 1, 3, 5);

int main() {
	CombatEngine::player.addPhysicalAbility(kickboxing);
	CombatEngine::player.addPhysicalAbility(muayThai);
	combat();
	return 0;
}