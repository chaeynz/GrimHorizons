#include "EconomyEngine.hpp"

void EconomyEngine::tryBuyItem(Player& targetPlayer, ShopInventory& targetShop, Item* targetItem) {
	if (checkItemAvailability(targetShop, targetItem) && checkPlayerFunds(targetPlayer, targetItem->getValue())) {
		
	}
	else {

	}
}

void EconomyEngine::buyItem(Player& targetPlayer, ShopInventory& targetShop, Item* targetItem) {
		if (checkPlayerFunds(targetPlayer, targetItem->getValue())) {
			if (checkInventoryItemsHasItem(targetShop.getItems(), targetItem)) {
				targetPlayer.addItemToInventory(targetItem);
					targetPlayer.removeGold(targetItem->getValue());
			}
			else {
				IOHandler::displayShopItemNotFound(targetItem);
			}
		}
		else {
			IOHandler::displayShopInsufficientGold(targetPlayer.getGold(), targetItem->getValue());
		} 	

		if (Weapon* weapon = dynamic_cast<Weapon*>(targetItem)) {
			targetPlayer.equipWeapon(dynamic_cast<Weapon*>(targetItem));
		}
}


bool EconomyEngine::checkItemAvailability(const ShopInventory& targetShop, Item* targetItem) {
	if (targetShop.findItem(targetItem) != targetShop.getItems().end()) {
		return true;
	}
	else {
		return false;
	}
}

bool EconomyEngine::checkPlayerFunds(const Player& targetPlayer, const int& itemPrice) {
	if (targetPlayer.getGold() >= itemPrice) {
		return true;
	}
	else {
		return false;
	}
}

/*void EconomyEngine::sellItemFromPlayerInventory(Player& targetPlayer, Item* targetItem) {
	if (checkInventoryItemsHasItem(targetPlayer.getInventory().getItems(), targetItem)) {
		if (checkPlayerFunds(targetPlayer, targetItem->getValue())) {
			targetPlayer.getInventory().removeItem(targetItem);
		}
	}
}*/

bool EconomyEngine::checkInventoryItemsHasItem(const std::map<Item*, std::pair<int, int>>& targetItems, Item* targetItem) {
	if (targetItems.find(targetItem) != targetItems.end()) {
		return true;
	}
	else {
		return false;
	}
}

void EconomyEngine::gainGold(Player& targetPlayer, const Enemy& targetEnemy) {
	targetPlayer.addGold(targetEnemy.getDropGold());
}

void EconomyEngine::gainExperience(Player& targetPlayer, const Enemy& targetEnemy) {
	targetPlayer.addExperience(targetEnemy.getDropExperience());
}

void EconomyEngine::gainRandomItemDrop(Player& targetPlayer, const Enemy& targetEnemy) {
	if (!targetEnemy.getDropTable().empty()) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distribution(0, targetEnemy.getDropTable().size() - 1);

		int randomIndex = distribution(gen);
		Item* randomItem = targetEnemy.getDropTable()[randomIndex];

		targetPlayer.addItemToInventory(randomItem);
	}
}