#pragma once

#include "../engine/EventHandler.hpp"

namespace event_handlers {
	extern void onPlayerDeath();
	extern void onEnemyDeath();
	extern void onPhysicalAbility();
	extern void onCombat();
	extern void onShop();
	extern void onSkilltree();
	extern void onMagicAbility();
	extern void onExperienceDistribution();
	extern void onLevelup();
	extern void onQuestCompleted();
	extern void onAchievementUnlocked();

	extern void onTimeElapsed();
}