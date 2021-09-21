#include "Character.h"
#include "Item.h"
#include <vector>
#include <iostream>

using namespace std;

Character::Character(int hp, std::string name, int atk) {
    this->maxHP = hp;
    this->HP = hp;
    this->name = name;
    this->Atk = atk;
    this->exp = 0;
    this->level = 0;
    this->alive = true;
}

std::vector<Item> Character::getInventory(){
    return this->inventory;
};

void Character::checkLvl() {
    if(exp >= 100){
        exp -= 100;
        level++;
    }
}

void Character::showCharacter(int num) {
    cout << "--------------------------------\n";
    cout << "- #"<< num << ": " << name << "\n";
    cout << "- level: " << level << "\n";
    cout << "- balance: " << gold << "\n";
}

void Character::addtoInventory(Item newItem) {
    inventory.push_back(newItem);
}

Item Character::getInventoryById(int id) {
    return inventory[id];
}

bool Character::fight(Character &enemy) {
    for(;;){
        enemy.HP -= this->Atk;
        if(enemy.HP <= 0){
            enemy.HP = 0;
            return true;
        }
        this->HP -= enemy.Atk;
        if(this->HP <= 0){
            this->HP = 0;
            return false;
        }
    }
}

void Character::rest() {
    HP = maxHP;
    std:: cout << "resting..\n\n\n";
    for(int i = 0; i < 1000000000; i++){

    }
    std::cout<<"now, i am ready to fight, sir. \n";
}