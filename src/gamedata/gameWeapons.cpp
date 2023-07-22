#include "gameWeapons.hpp"

Weapon* woodenSword = new Weapon("Wooden Sword", "This is a standard wooden sword", Rarity::Common, 5, 1, 1, 2);
Weapon* copperSword = new Weapon("Copper Sword", "Atleast it's better than wood!", Rarity::Common, 10, 2, 1.5, 3.5);

Weapon* weapon_NewArmy1885 = new Weapon("New Army", "G-g-g-g-un?", Rarity::Epic, 800, 17, 0.9, 12);
Weapon* weapon_Beretta92 = new Weapon("Beretta 92", "", Rarity::Rare, 1000, 20, 1.2, 11);
Weapon* weapon_Colt9mmSMG = new Weapon("Colt 9mm SMG", "", Rarity::Special, 2000, 21, 3.2, 27);
Weapon* weapon_Gewehr98 = new Weapon("Gewehr 98", "Bolt-action rifle", Rarity::Rare, 900, 17, static_cast<float>(1.8), 16);
Weapon* weapon_L22Carbine = new Weapon("L22 Carbine", "", Rarity::Epic, 1200, 19, 2.1, 21);
Weapon* weapon_SawedOff = new Weapon("Sawed-off Shotgun", "", Rarity::Legendary, 2500, 30, 2, 50);