#include "EconomyEngine.hpp"

void EconomyEngine::buyItem(Player& targetPlayer, ShopInventory& targetShop, Item* targetItem) {
	if (targetShop.findItem(targetItem) != targetShop.getItems().end()) {
		targetPlayer.addItemToInventory(targetItem);
	}
}