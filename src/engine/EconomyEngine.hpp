#pragma once

#include "IOHandler.hpp"

#include "../components//Player.hpp"
#include "../components/Enemy.hpp"
#include "../components/Item.hpp"
#include "../components/ShopInventory.hpp"

#include <random>


class EconomyEngine
{
public:
	static bool checkItemAvailability(const ShopInventory& targetShop, Item* targetItem);
	static bool checkPlayerFunds(const Player& targetPlayer, const int& itemPrice);
	static bool checkInventoryItemsHasItem(const std::map<Item*, std::pair<int, int>>& targetItems, Item* targetItem);
	static void sellItemFromPlayerInventory(Player& targetPlayer, Item* targetItem);
	static void buyItem(Player& targetPlayer, ShopInventory& targetShop, Item* targetItem);
	static void tryBuyItem(Player& targetPlayer, ShopInventory& targetShop, Item* targetItem);



	static void gainRandomItemDrop(Player& targetPlayer, const Enemy& targetEnemy);
	static void gainGold(Player& targetPlayer, const Enemy& targetEnemy);
	static void gainExperience(Player& targetPlayer, const Enemy& targetEnemy);
};