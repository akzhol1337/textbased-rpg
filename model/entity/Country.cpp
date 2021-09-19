#include "Country.h"
#include "City.h"
#include <string>

Country::Country(std::string title) {
    this->title = title;
}

void Country::addCity(City newCity) {
    this->cities.push_back(newCity);
}
