// CombatEngine.hpp
#pragma once

#include <algorithm>
#include <iostream>
#include "../components/Enemy.hpp"
#include "../components/Player.hpp"
#include "../components/Ability.hpp"
#include "../gamedata/gameAbilities.hpp"

#include "IOHandler.hpp"

class CombatEngine {
public:
	static Player player;
	static Enemy enemy;

	static bool isEnemyAlive();
	static bool isPlayerAlive();

	static void fight();

	static void attackPlayer();
	static void attackEnemy(const Weapon* weapon);
	static void attackEnemy(const PhysicalAbility* physicalAbility);
	static void attackEnemy(const MagicAbility* magicAbility);

	static void distributeExperience();
	static void distributeGold();
	static void distributeLoot();

	static void dropEnemy();

	static PhysicalAbility* selectPhysicalAbility();
	static MagicAbility* selectMagicAbility();

	static float calculatePlayerDamage(const float phyicalAbilityDamage);
	static float calculatePlayerDamage();
	static float calculateEnemyDamage();
};