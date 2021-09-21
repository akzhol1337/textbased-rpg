#include <vector>
#include <string>
#include "Item.h"

#ifndef TEXTBASED_RPG_CHARACTER_H
#define TEXTBASED_RPG_CHARACTER_H

class Character {
public:
    int HP;
    std::string name;
    bool alive;
    int maxHP;
    int Atk;
    int gold;
    int exp;
    int level;
    int kills;

    Character(int hp, std::string name, int atk);

    std::vector<Item> &getInventory();
    void checkLvl();
    void showStatistics();
    void showCharacter(int num);
    void addtoInventory(Item newItem);
    Item getInventoryById(int id);
    bool fight(Character &enemy);
    void rest();
private:
    std::vector<Item> inventory;
};


#endif //TEXTBASED_RPG_CHARACTER_H
