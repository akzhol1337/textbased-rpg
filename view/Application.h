#include "../model/entity/Character.h"
#include "../model/entity/Country.h"

#ifndef TEXTBASED_RPG_APPLICATION_H
#define TEXTBASED_RPG_APPLICATION_H

class Application {
public:
    void start(Country &country);
    void newGame(Country &country);
    Character *createPerson();
    void discoverMap(Character &mainCharacter, Country &country);
    void exploreCity(Character &mainCharacter, City &city);
};


#endif //TEXTBASED_RPG_APPLICATION_H
