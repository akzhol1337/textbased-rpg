#include "../model/entity/Character.h"
#include "../model/entity/Country.h"
#include <vector>

#ifndef TEXTBASED_RPG_APPLICATION_H
#define TEXTBASED_RPG_APPLICATION_H

class Application {
public:

    std::vector<Item>shopItems;

    void start(Country &country);
    void newGame(Country &country);
    static Character *createPerson();
    void discoverMap(Character &mainCharacter, Country &country);
    void exploreCity(Character &mainCharacter, City &city);
    //void statistics(Character &mainCharacter);
    void showInventory(Character &mainCharacter);
    void work(Character &mainCharacter);
    void relax(Character &mainCharacter);
    void shop(Character &mainCharacter);
};


#endif //TEXTBASED_RPG_APPLICATION_H
