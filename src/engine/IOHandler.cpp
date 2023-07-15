#include "IOHandler.hpp"

void IOHandler::displayPlayerDeath() {
	std::cout << "Better luck next time!\n";
}

void IOHandler::displayCausedDamage(std::string causerName, std::string receiverName, float causedDamage, float receiverHealth, float receiverMaxHealth) {
	std::cout << causerName << " dealt ~" << std::ceil(causedDamage) << " damage to " << receiverName << std::endl;
	std::cout << receiverName << " has " << std::fixed << std::setprecision(2) << receiverHealth << "/" << receiverMaxHealth << " remaining\n";
}

void IOHandler::displayInventory(Inventory& inventory) {
	std::cout << "Inventory:\n";
	for (const auto& pair : inventory.getItems()) {
		const Item& item = pair.first;
		int quantity = pair.second;
		std::cout << "Item: " << item.getName() << ", Quantity: " << quantity << std::endl;
	}
}

void IOHandler::displayPhysicalAbilities(const std::vector<PhysicalAbility*>& physicalAbilities) {
	std::cout << "Available Physical Abilities:\n";
	for (size_t i = 0; i < physicalAbilities.size(); ++i) {
		std::cout << i + 1 << ". " << physicalAbilities[i]->getName() << std::endl;
	}
	std::cout << std::endl; 
}
void IOHandler::displayMagicAbilities(const std::vector<MagicAbility*>& magicAbilities) {
	std::cout << "Available Magic Abilities:\n";
	for (size_t i = 0; i < magicAbilities.size(); ++i) {
		std::cout << i + 1 << ". " << magicAbilities[i]->getName() << std::endl;
	}
	std::cout << std::endl;
}
void IOHandler::displaySelectionPhysicalAbilities(const std::vector <PhysicalAbility*>& physicalAbilities) {
		displayPhysicalAbilities(physicalAbilities);
		std::cout << "Select a Physical Ability: ";
}
void IOHandler::displaySelectionMagicAbilities(const std::vector <MagicAbility*>& magicAbilities) {
	displayMagicAbilities(magicAbilities);
	std::cout << "Select a Magic Ability: ";
}
void IOHandler::displaySelectionCombatOptions(std::vector<PhysicalAbility*> playerPhysicalAbilites, std::vector<MagicAbility*> playerMagicAbilites, Weapon* playerEquippedWeapon) {
	int i = 1;
	if (!playerPhysicalAbilites.empty()) {
		std::cout << i++ << ". Attack with physical ability\n";
	} 
	if (!playerMagicAbilites.empty()) {
		std::cout << i++ << ". Attack with magic ability\n";
	}
	if (playerEquippedWeapon != nullptr) {
		std::cout << i++ << ". Attack with weapon\n";
	}

	// displayPromptInput();
}

void IOHandler::displayInvalidChoice() {
	std::cout << "\nInvalid choice.\n\n";
}

PhysicalAbility* IOHandler::readSelectionPhysicalAbilities(const std::vector<PhysicalAbility*>& physicalAbilities) {
	int choice;
	std::cin >> choice;
	if (choice >= 1 && choice <= static_cast<int>(physicalAbilities.size())) {
		return physicalAbilities[choice - 1];
	}
	else {
		displayInvalidChoice();
		displaySelectionPhysicalAbilities(physicalAbilities);
		return readSelectionPhysicalAbilities(physicalAbilities);
	}
}

MagicAbility* IOHandler::readSelectionMagicAbilities(const std::vector<MagicAbility*>& magicAbilities) {
	int choice;
	std::cin >> choice;
	if (choice >= 1 && choice <= static_cast<int>(magicAbilities.size())) {
		return magicAbilities[choice - 1];
	}
	else {
		displayInvalidChoice();
		displaySelectionMagicAbilities(magicAbilities);
		return readSelectionMagicAbilities(magicAbilities);
	}
}

CombatOption IOHandler::readSelectionCombatOptions(std::vector<PhysicalAbility*> playerPhysicalAbilities, std::vector<MagicAbility*> playerMagicAbilities, Weapon* playerEquippedWeapon) {
	int choice;
	std::cin >> choice;

	if (!playerPhysicalAbilities.empty() && choice == 1) {
		return CombatOption::PhysicalAbility;
	}
	if ((!playerPhysicalAbilities.empty() && !playerMagicAbilities.empty() && choice == 2) || (playerPhysicalAbilities.empty() && !playerMagicAbilities.empty() && choice == 1)) {
		return CombatOption::MagicAbility;
	}
	if ((!playerPhysicalAbilities.empty() && !playerMagicAbilities.empty() && playerEquippedWeapon != nullptr && choice == 3) || ((playerPhysicalAbilities.empty() != playerMagicAbilities.empty()) && playerEquippedWeapon != nullptr && choice == 2) || ((playerPhysicalAbilities.empty() && playerMagicAbilities.empty()) && playerEquippedWeapon != nullptr && choice == 1)) {
		return CombatOption::EquippedWeapon;
	}
}