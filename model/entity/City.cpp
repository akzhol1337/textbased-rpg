#include "City.h"
#include <iostream>

using namespace std;

City::City(std::string title) {
    this->title = title;
}

void City::showCity(int num) {
    cout << "--------------------------------\n";
    cout << "- #"<< num << ": " << title << "\n";
    cout << "- " << citizens.size() << " population\n";
}

void City::addCitizen(Character citizen) {
    this->citizens.push_back(citizen);
}