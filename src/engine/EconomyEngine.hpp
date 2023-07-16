#pragma once

#include "../components//Player.hpp"
#include "../components/Enemy.hpp"
#include "../components/Item.hpp"
#include "../components/ShopInventory.hpp"


class EconomyEngine
{
public:
	static void buyItem(Player& targetPlayer, ShopInventory& targetShop, Item* targetItem);
};

