#pragma once

#include <string>
#include <vector>
#include "Enemy.hpp"

class Level {
protected:
	static int lastAssignedId;
	int id;
	std::string name;
	std::vector<Enemy> enemies;

public:
	Level(std::string levelName, std::vector<Enemy> levelEnemies);
};