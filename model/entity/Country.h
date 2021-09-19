#include <string>
#include <vector>
#include "Character.h"
#include "City.h"

#ifndef TEXTBASED_RPG_COUNTRY_H
#define TEXTBASED_RPG_COUNTRY_H


class Country {
public:
    std::string title;
    std::vector<City> cities;
    Country(std::string title);
    void addCity(City newCity);
};


#endif //TEXTBASED_RPG_COUNTRY_H
