#include <vector>
#include "Item.h"

#ifndef TEXTBASED_RPG_CHARACTER_H
#define TEXTBASED_RPG_CHARACTER_H


class Character {
public:
    int HP;
    int maxHP;
    int Atk;
    int exp;
    int level;
private:
    int gold;
    std::vector<Item> inventory;
};


#endif //TEXTBASED_RPG_CHARACTER_H
