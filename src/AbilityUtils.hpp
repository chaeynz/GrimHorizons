#pragma once

#include "Ability.hpp"

PhysicalAbility* createPhysicalAbility(std::string& abilityName, std::string& abilityDescription, int abilityRequiredLevel, float physicalAbilityDamage);
PhysicalAbility* createPhysicalAbility(const char* abilityName, const char* abilityDescription, int abilityRequiredLevel, float physicalAbilityDamage);