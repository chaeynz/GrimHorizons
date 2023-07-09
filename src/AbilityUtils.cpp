#include "AbilityUtils.hpp"

PhysicalAbility createPhysicalAbility(std::string& abilityName, std::string& abilityDescription, int abilityRequiredLevel, float physicalAbilityDamage) {
	return PhysicalAbility(abilityName, abilityDescription, abilityRequiredLevel, physicalAbilityDamage);
}

PhysicalAbility createPhysicalAbility(const char* abilityName, const char* abilityDescription, int abilityRequiredLevel, float physicalAbilityDamage) {
	return PhysicalAbility(abilityName, abilityDescription, abilityRequiredLevel, physicalAbilityDamage);
}