#ifndef TEXTBASED_RPG_CITY_H
#define TEXTBASED_RPG_CITY_H

#include <string>
#include <vector>
#include "Character.h"

class City {
public:
    std::string title;
    std::vector<Character> citizens;

    City(std::string title);
    void addCitizen(Character citizen);
};


#endif //TEXTBASED_RPG_CITY_H
