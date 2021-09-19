#include "Application.h"
#include "../model/entity/Character.h"
#include "../model/entity/Country.h"
#include <bits/stdc++.h>

using namespace std;

void Application::start(Country &country) {
    cout << "----------------------------------------\n";
    cout << "Welcome to text based RPG Game:         \n";
    cout << "1: Start a new game                     \n";
    cout << "2: Choose saved game                    \n";
    cout << "3: Exit                                 \n";

    int choice;
    cin >> choice;

    switch(choice){
        case 3:
            exit(0);
        case 1:
            newGame(country);
    }

}

Character *Application::createPerson() {
    string name;
    int hp, attack;

    int balance = 200;

    printf("Hello, create a new Character\n");
    printf("Enter a name: ");

    cin >> name;
    printf("\n");

    printf("Enter a maximum HP (0 - %d): ", balance);
    scanf("%d", &hp);
    balance -= hp;
    printf("\n");
    printf("Enter a maximum attack (0 - %d): ", balance);
    scanf("%d", &attack);
    printf("\n");

    cout << "Welcome, " << name << "!\n";

    return new Character(hp, name, attack);
}

void Application::discoverMap(Character &mainCharacter, Country &country) {
    printf("Welcome to Berland!!!\n");

    vector<City> cities = country.cities;
    int num = 0;
    for(City &city : cities){
        printf("------------------\n");
        cout << "--- #" << num << ":" << city.title << "---\n";
        printf("--- %d citizens living --\n", (int)city.citizens.size());
        printf("-----------------\n\n");
        num++;
    }

    int choice;
    printf("Choose city to go!");
    scanf("%d", &choice);

    exploreCity(mainCharacter, cities[choice]);
}

void Application::exploreCity(Character &mainCharacter, City &city) {
    cout << "Welcome to " << city.title << "\n";
    printf("We have %d citizens in our city\n", (int)city.citizens.size());

    printf("----------------------------\n");

    int num = 0;
    for(Character &character : city.citizens){
        printf("------------\n");
        cout << "#" << num << ": " << "Name: " << character.name << "\n";
        cout << "level: " << character.level << "\n";
        printf("------------\n");
    }

    printf("You wanna fight? (y/n)");
    char choice;
    cin >> choice;

    if(choice == 'y'){
        printf("Choose an enemy\n");
        int enemyId;
        scanf("%d", &enemyId);

    } else {
        return;
    }

}

void Application::newGame(Country &country) {
    Character *mainCharacter = createPerson();
    int choice;

    printf("--------------------\n");
    printf("1: Map              \n");
    printf("2: Inventory        \n");
    printf("3: Shop             \n");
    printf("4: Work             \n");
    printf("5: Go home          \n");
    printf("6: Statistics       \n");
    printf("----------------------");

    cin >> choice;

    switch(choice){
        case 1:
            discoverMap(*mainCharacter, country);
    }








}
