#pragma once

#include <string>

class Ability {
protected:
	std::string name;
	std::string description;
	int requiredLevel;

public:
	Ability(std::string& abilityName, std::string abilityDescription, int abilityRequiredLevel) : name(abilityName), description(abilityDescription), requiredLevel(abilityRequiredLevel) {

	}
	Ability(const char* abilityName, const char* abilityDescription, int abilityRequiredLevel) : name(abilityName), description(abilityDescription), requiredLevel(abilityRequiredLevel) {

	}
	
	virtual ~Ability() {

	}

	// Polymorphism
	virtual std::string getDescription() {
		return description;
	}


	// Getter functions
	std::string getName() const {
		return name;
	}
	
	int getRequiredLevel() const {
		return requiredLevel;
	}
};

class PhysicalAbility : public Ability { //Boxing, Kickboxing, MuayThai, JiuJitsu?
protected:
	float damage;
public:
	PhysicalAbility(std::string& abilityName, std::string& abilityDescription, int abilityRequiredLevel, float physicalAbilityDamage) : Ability(abilityName, abilityDescription, abilityRequiredLevel), damage(physicalAbilityDamage) {

	}
	PhysicalAbility(const char* abilityName, const char* abilityDescription, int abilityRequiredLevel, float physicalAbilityDamage) : Ability(abilityName, abilityDescription, abilityRequiredLevel), damage(physicalAbilityDamage) {

	}

	// Getter functions
	float getDamage() const {
		return damage;
	}
};

class MagicAbility : public Ability {

};