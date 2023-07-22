#include "shop.hpp"

void shop() {

	ShopInventory gameShop;
	gameShop.addItem(woodenSword, woodenSword->getValue());
	gameShop.addItem(weapon_Beretta92, weapon_Beretta92->getValue());
	gameShop.addItem(weapon_NewArmy1885, weapon_NewArmy1885->getValue());
	gameShop.addItem(weapon_Colt9mmSMG, weapon_Colt9mmSMG->getValue());


	IOHandler::displayShopInventory(gameShop.getItems());
	EconomyEngine::buyItem(CombatEngine::player, gameShop, IOHandler::readSelectionShopInventory(gameShop));
	IOHandler::displayInventory(CombatEngine::player.getInventory());
}