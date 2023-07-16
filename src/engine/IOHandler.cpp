#include "IOHandler.hpp"

void IOHandler::displayPlayerDeath() {
	std::cout << "Better luck next time!\n";
}

void IOHandler::displayCausedDamage(const std::string& causerName, const  std::string& receiverName, const  float& causedDamage, const  float& receiverHealth, const  float& receiverMaxHealth) {
	std::cout << causerName << " dealt ~" << std::ceil(causedDamage) << " damage to " << receiverName << std::endl;
	std::cout << receiverName << " has " << std::fixed << std::setprecision(2) << receiverHealth << "/" << receiverMaxHealth << " remaining\n\n";
}

void IOHandler::displayInventory(const Inventory& inventory) {
	std::cout << "\nInventory:\n";
	for (const auto& pair : inventory.getItems()) {
		const Item& item = pair.first;
		int quantity = pair.second;
		std::cout << "Item: " << item.getName() << ", Quantity: " << quantity << std::endl;
	}
}

void IOHandler::displayPhysicalAbilities(const std::vector<PhysicalAbility*>& physicalAbilities) {
	std::cout << "\n\nAvailable Physical Abilities:\n\n";
	for (size_t i = 0; i < physicalAbilities.size(); ++i) {
		std::cout << "\t" << i + 1 << ". " << physicalAbilities[i]->getName() << std::endl;
	}
}
void IOHandler::displayMagicAbilities(const std::vector<MagicAbility*>& magicAbilities) {
	std::cout << "\n\nAvailable Magic Abilities:\n\n";
	for (size_t i = 0; i < magicAbilities.size(); ++i) {
		std::cout << i + 1 << ". " << magicAbilities[i]->getName() << std::endl;
	}
	std::cout << std::endl;
}
void IOHandler::displaySelectionPhysicalAbilities(const std::vector <PhysicalAbility*>& physicalAbilities) {
	displayPhysicalAbilities(physicalAbilities);
	displayPromptForInput();
}
void IOHandler::displaySelectionMagicAbilities(const std::vector <MagicAbility*>& magicAbilities) {
	displayMagicAbilities(magicAbilities);
	displayPromptForInput();
}
void IOHandler::displaySelectionCombatOptions(const std::vector<PhysicalAbility*>& playerPhysicalAbilites, const std::vector<MagicAbility*>& playerMagicAbilites, Weapon* playerEquippedWeapon) {
	int i = 1;

	std::cout << "Available Attacks:\n\n";

	if (!playerPhysicalAbilites.empty()) {
		std::cout << "\t" << i++ << ". Attack with physical ability\n";
	} 
	if (!playerMagicAbilites.empty()) {
		std::cout << "\t" << i++ << ". Attack with magic ability\n";
	}
	if (playerEquippedWeapon != nullptr) {
		std::cout << "\t" << i++ << ". Attack with weapon\n";
	}

	displayPromptForInput();
}

void IOHandler::displayNotifySelectedPhysicalAbility(const PhysicalAbility* physicalAbility) {
	system("cls");
	std::cout << "\nYou selected " << physicalAbility->getName() << "!\n";
}
void IOHandler::displayNotifySelectedMagicAbility(const MagicAbility* magicAbility) {
	system("cls");
	std::cout << "\nYou selected " << magicAbility->getName() << "!\n";
}
void IOHandler::displayNotifySelectedEquippedWeapon(const Weapon* equippedWeapon) {
	system("cls");
	std::cout << "\nYou selected " << equippedWeapon->getName() << "!\n";
}

void IOHandler::displayInvalidChoice() {
	std::cout << "\nInvalid choice.\n\n";
}

void IOHandler::displayPromptForInput() {
	std::cout << "\nSelect an Option: ";
}

int IOHandler::readChoice() { // THE ONLY ACTUAL READER ITS SO GOOD
	int choice;
	while (true) {
		if (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return 0;
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return choice;
		}
	}
}

PhysicalAbility* IOHandler::readSelectionPhysicalAbilities(const std::vector<PhysicalAbility*>& physicalAbilities) {
	int choice;
	choice = readChoice();
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
	choice = readChoice();
	if (choice >= 1 && choice <= static_cast<int>(magicAbilities.size())) {
		return magicAbilities[choice - 1];
	}
	else {
		displayInvalidChoice();
		displaySelectionMagicAbilities(magicAbilities);
		return readSelectionMagicAbilities(magicAbilities);
	}
}

CombatOption IOHandler::readSelectionCombatOptions(const std::vector<PhysicalAbility*>& playerPhysicalAbilities, const std::vector<MagicAbility*>& playerMagicAbilities, Weapon* playerEquippedWeapon) {
	int choice;
	choice = readChoice();

	if (!playerPhysicalAbilities.empty() && choice == 1) {
		return CombatOption::PhysicalAbility;
	}
	if ((!playerPhysicalAbilities.empty() && !playerMagicAbilities.empty() && choice == 2) || (playerPhysicalAbilities.empty() && !playerMagicAbilities.empty() && choice == 1)) {
		return CombatOption::MagicAbility;
	}
	if ((!playerPhysicalAbilities.empty() && !playerMagicAbilities.empty() && playerEquippedWeapon != nullptr && choice == 3) || ((playerPhysicalAbilities.empty() != playerMagicAbilities.empty()) && playerEquippedWeapon != nullptr && choice == 2) || ((playerPhysicalAbilities.empty() && playerMagicAbilities.empty()) && playerEquippedWeapon != nullptr && choice == 1)) {
		return CombatOption::EquippedWeapon;
	}
	else {
		displayInvalidChoice();
		displaySelectionCombatOptions(playerPhysicalAbilities, playerMagicAbilities, playerEquippedWeapon);
		return readSelectionCombatOptions(playerPhysicalAbilities, playerMagicAbilities, playerEquippedWeapon);
	}
}