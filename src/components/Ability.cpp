// Ability.cpp
#include "Ability.hpp"


Ability::Ability() {

	}


	Ability::Ability(std::string& abilityName, const std::string abilityDescription, int abilityRequiredLevel) : name(abilityName), description(abilityDescription), requiredLevel(abilityRequiredLevel) {

	}
	Ability::Ability(const char* abilityName, const char* abilityDescription, int abilityRequiredLevel) : name(abilityName), description(abilityDescription), requiredLevel(abilityRequiredLevel) {

	}

	Ability::~Ability() {

	}


	// Getter functions
	std::string Ability::getName() const {
		return name;
	}
	std::string Ability::getDescription() const {
		return description;
	}
	int Ability::getRequiredLevel() const {
		return requiredLevel;
	}


	PhysicalAbility::PhysicalAbility(std::string& abilityName, std::string& abilityDescription, int abilityRequiredLevel, float physicalAbilityDamage) : Ability(abilityName, abilityDescription, abilityRequiredLevel), damage(physicalAbilityDamage) {

	}
	PhysicalAbility::PhysicalAbility(const char* abilityName, const char* abilityDescription, int abilityRequiredLevel, float physicalAbilityDamage) : Ability(abilityName, abilityDescription, abilityRequiredLevel), damage(physicalAbilityDamage) {

	}

	// Getter functions
	std::string PhysicalAbility::getName() const {
		return name;
	}
	std::string PhysicalAbility::getDescription() const {
		return description;
	}
	int PhysicalAbility::getRequiredLevel() const {
		return requiredLevel;
	}
	float PhysicalAbility::getDamage() const {
		return damage;
	}
