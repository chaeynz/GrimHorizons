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

void IOHandler::displayPhysicalAbilities(const std::vector<PhysicalAbility*>& abilities) {
	std::cout << "Available Abilities:\n";
	for (size_t i = 0; i < abilities.size(); ++i) {
		std::cout << i + 1 << ". " << abilities[i]->getName() << std::endl;
	}
	std::cout << std::endl;
}
void IOHandler::displaySelectionPhysicalAbilities(const std::vector <PhysicalAbility*>& abilities) {
		displayPhysicalAbilities(abilities);
		std::cout << "Select an ability: ";
}
void IOHandler::displaySelectionCombatMenu(std::vector<PhysicalAbility*> playerPhysicalAbilites, std::vector<MagicAbility*> playerMagicAbilites, Weapon* playerEquippedWeapon) {
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

PhysicalAbility* IOHandler::readSelectionPhysicalAbilities(const std::vector<PhysicalAbility*>& abilities) {
	int choice;
	std::cin >> choice;
	if (choice >= 1 && choice <= static_cast<int>(abilities.size())) {
		return abilities[choice - 1];
	}
	else {
		displayInvalidChoice();
		displaySelectionPhysicalAbilities(abilities);
		return readSelectionPhysicalAbilities(abilities);
	}
}

static CombatOption readSelectionCombatOptions(std::vector<PhysicalAbility*> playerPhysicalAbilites, std::vector<MagicAbility*> playerMagicAbilites, Weapon* playerEquippedWeapon) {
	int choice;
	std::cin >> choice;

	if (!playerPhysicalAbilites.empty()) {

	}
	if (!playerMagicAbilites.empty()) {
	}
	if (playerEquippedWeapon != nullptr) {
	}
}