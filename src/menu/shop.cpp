#include "shop.hpp"

void shop() {

	ShopInventory gameShop;
	gameShop.addItem(woodenSword, 10, 1);

	IOHandler::displaySelectionShopInventory(gameShop.getItems());
	EconomyEngine::buyItem(CombatEngine::player, gameShop, IOHandler::readSelectionShopInventory(gameShop, woodenSword));

}