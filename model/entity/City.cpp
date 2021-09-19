#include "City.h"

City::City(std::string title) {
    this->title = title;
}

void City::addCitizen(Character citizen) {
    this->citizens.push_back(citizen);
}