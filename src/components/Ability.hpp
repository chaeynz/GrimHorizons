// Ability.hpp
#pragma once

#include <string>

class Ability {
protected:
	std::string name;
	std::string description;
	int requiredLevel;

public:
	Ability(std::string& abilityName, const std::string abilityDescription, int abilityRequiredLevel);
	Ability(const char* abilityName, const char* abilityDescription, int abilityRequiredLevel);
	
	virtual ~Ability();

	// Getter functions
	virtual std::string getName() const;
	virtual std::string getDescription() const;
	virtual int getRequiredLevel() const;

};

class PhysicalAbility : public Ability { //Boxing, Kickboxing, MuayThai, JiuJitsu?
protected:
	float damage;
public:
	PhysicalAbility(std::string& abilityName, std::string& abilityDescription, int abilityRequiredLevel, float physicalAbilityDamage);
	PhysicalAbility(const char* abilityName, const char* abilityDescription, int abilityRequiredLevel, float physicalAbilityDamage);

	// Getter functions
	std::string getName() const;
	std::string getDescription() const;
	int getRequiredLevel() const;
	float getDamage() const;
};

class MagicAbility : public Ability {

};