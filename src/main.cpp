#include "engine/CombatEngine.hpp"
#include "engine/EventHandler.hpp"
#include "components/Player.hpp"
#include "components/Enemy.hpp"

#include "menu/combat.hpp"
#include "menu/shop.hpp"

#include "engine/EconomyEngine.hpp"

#include <Windows.h>

Player CombatEngine::player = Player("Kevin");
Enemy CombatEngine::enemy = Enemy("Zombie", 5, 10, 2, 1, 3, 5);

int main() {
	CombatEngine::player.addPhysicalAbility(kickboxing);
	CombatEngine::player.addPhysicalAbility(muayThai);

	while (true) {
		IOHandler::displaySelectionMainmenuOptions();
		MainmenuOption selectedMainmenuOption = IOHandler::readSelectionMainmenuOptions();

		system("cls");
		if (selectedMainmenuOption == MainmenuOption::Combat) {
			combat();
		}
		else if (selectedMainmenuOption == MainmenuOption::Shop) {
			shop();
		}
		else if (selectedMainmenuOption == MainmenuOption::Inventory) {
			IOHandler::displayInventory(CombatEngine::player.getInventory());
		}
		else if (selectedMainmenuOption == MainmenuOption::AbilityTree) {

		}
		else if (selectedMainmenuOption == MainmenuOption::Credit) {

		}
		else if (selectedMainmenuOption == MainmenuOption::Quit) {
			return 0;
		}
		Sleep(2000);
	}
}