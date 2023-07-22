#include "Level.hpp"

Level::Level(std::string levelName, std::vector<Enemy> levelEnemies) : id(++lastAssignedId), name(levelName), enemies(levelEnemies) {

}
