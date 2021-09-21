#include "Application.h"
#include "../model/entity/Item.h"
#include "../model/entity/Character.h"
#include "../model/entity/Country.h"
#include <bits/stdc++.h>

using namespace std;

void Application::start(Country &country) {

    shopItems.push_back(*new Item("Axe", 32, 50));
    shopItems.push_back(*new Item("Bow", 15, 30));
    shopItems.push_back(*new Item("Sword", 70, 65));
    shopItems.push_back(*new Item("Pistol", 300, 500));
    shopItems.push_back(*new Item("RPG", 9999999, 1000000));
    shopItems.push_back(*new Item("Knife", 30, 45));
    shopItems.push_back(*new Item("Bomb", 100000, 200506));
    shopItems.push_back(*new Item("Axe", 32, 50));
    shopItems.push_back(*new Item("nunchucks", 90, 175));

    printf("               .__                                   __                                  \n"
           "__  _  __ ____ |  |   ____  ____   _____   ____    _/  |_  ____    _____________   ____  \n"
           "\\ \\/ \\/ // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\   \\   __\\/  _ \\   \\_  __ \\____ \\ / ___\\ \n"
           " \\     /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/    |  | (  <_> )   |  | \\/  |_> > /_/  >\n"
           "  \\/\\_/  \\___  >____/\\___  >____/|__|_|  /\\___  >   |__|  \\____/    |__|  |   __/\\___  / \n"
           "             \\/          \\/            \\/     \\/                          |__|  /_____/  \n");
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
    printf("Enter a maximum attack (0 - %d): ", max(0, balance));
    scanf("%d", &attack);
    printf("\n");

    cout << "Welcome, " << name << "!\n";

    return new Character(hp, name, attack);
}

void Application::discoverMap(Character &mainCharacter, Country &country) {
    printf("\nWelcome to Berland!!!\n\n");

    vector<City> cities = country.cities;
    int num = 0;
    for(City &city : cities){
        num++;
        city.showCity(num);
    }
    printf("--------------------------------\n");

    int choice;
    printf("Choose city to go!");
    scanf("%d", &choice);

    exploreCity(mainCharacter, cities[choice-1]);
}

void Application::work(Character &mainCharacter) {
    printf("Nice work !\n Come back next day\n Gained: %d gold\n", mainCharacter.level * 10);
    mainCharacter.gold += mainCharacter.level * 10;
}

void Application::relax(Character &mainCharacter) {
    printf("Uhhmm, now I am ready to fight, sir. HP:%d/%d", mainCharacter.maxHP, mainCharacter.maxHP);
    mainCharacter.HP = mainCharacter.maxHP;
}

void Fight(Character &mainCharacter, Character &enemyCharacter){
    bool win = mainCharacter.fight(enemyCharacter);
    printf("********************************\n");

    printf("* Welcome to battle field\n");

    cout << mainCharacter.name << "\n\n";

    printf("____   _____________\n"
           "\\   \\ /   /   _____/\n"
           " \\   Y   /\\_____  \\ \n"
           "  \\     / /        \\\n"
           "   \\___/ /_______  /\n"
           "                 \\/ \n\n");

    cout << enemyCharacter.name << "\n";

    if(win) {

        mainCharacter.gold += enemyCharacter.gold;
        mainCharacter.level += enemyCharacter.level;
        mainCharacter.kills++;

        enemyCharacter.alive = false;

        printf("\n\nCongratz, you win!!!!\n");
        printf("You gain: %d exp, %d gold\n", enemyCharacter.level * 10, enemyCharacter.gold);

        mainCharacter.exp += enemyCharacter.level * 10;
        mainCharacter.checkLvl();

        if(enemyCharacter.getInventory().empty()) return;
        printf("His inventory :\n");

        int num = 0;

        for(auto &to : enemyCharacter.getInventory()){
            to.showItem(num);
            num++;
        }
        printf("Input a item to choose, -1 to return\n");
        int choice;
        cin >> choice;
        if(choice == -1)
            return;
        mainCharacter.addtoInventory(enemyCharacter.getInventoryById(choice));
        mainCharacter.Atk += enemyCharacter.getInventoryById(choice).damage;
    } else {
        printf("\n\n                                                         \n"
               "   _________    _____   ____     _______  __ ___________ \n"
               "  / ___\\__  \\  /     \\_/ __ \\   /  _ \\  \\/ // __ \\_  __ \\\n"
               " / /_/  > __ \\|  Y Y  \\  ___/  (  <_> )   /\\  ___/|  | \\/\n"
               " \\___  (____  /__|_|  /\\___  >  \\____/ \\_/  \\___  >__|   \n"
               "/_____/     \\/      \\/     \\/                   \\/       \n");
        exit(0);
    }
}

void Application::exploreCity(Character &mainCharacter, City &city) {
    cout << "------------------------------------------------------------\n\n";
    cout << "Welcome to " << city.title << "\n";
    printf("We have %d citizens in our city\n\n", (int)city.citizens.size());

    int num = 0;
    for(Character &character : city.citizens){
        num++;
        if(character.alive) {
            character.showCharacter(num);
        }
    }

    printf("You wanna fight? (y/n): \n");
    char choice;
    cin >> choice;
    printf("\n");

    if(choice == 'y'){
        printf("Choose an enemy\n");
        int enemyId;
        scanf("%d", &enemyId);
        Fight(mainCharacter, city.citizens[enemyId-1]);
    } else {
        return;
    }
}

void Application::shop(Character &mainCharacter) {
    printf("**************************\n");
    printf("Welcome to our shop!\n");

    for(;;){
        int choice;
        printf("#1: Buy item\n");
        printf("#2: Check all items\n");
        printf("#: Exit shop\n");

        scanf("%d", &choice);

        if(choice == 1){
            printf("Input id of item:\n");
            int id;
            scanf("%d", &id);

            if(mainCharacter.getInventory().size() >= 3){
                printf("Sorry, your inventory is full :(\n");
            } else {
                if(shopItems[id].price > mainCharacter.gold){
                    printf("Sorry, you don't have enough gold to buy that:(\n");
                } else {
                    mainCharacter.getInventory().push_back(shopItems[id]);
                    mainCharacter.gold -= shopItems[id].price;
                    mainCharacter.Atk += shopItems[id].damage;

                    printf("Congratulations!\n");
                }
            }


        } else if(choice == 2){
            int num = 0;
            for(Item item : shopItems){
                item.showItem(num);
                num++;
            }
            printf("\n");
        } else {
            return;
        }
    }
}

void Application::showInventory(Character &mainCharacter) {
    vector<Item> &items = mainCharacter.getInventory();

    if(items.empty()){
        printf("Your inventory is empty!\n");
        return;
    }

    printf("---------------------\n");

    int num = 0;

    for(Item item : items){
        item.showItem(num);
        num++;
    }

    if(items.empty()) return;
    printf("\n Sell item? (y/n)\n");

    char choice;
    cin >> choice;

    if(choice == 'y'){
        printf("Input id of item\n");
        int id;
        scanf("%d", &id);
        items.erase(items.begin() + id);

    } else {
        return;
    }
}


void Application::newGame(Country &country) {
    Character *mainCharacter = createPerson();
    int choice;

    for(;;) {
        while (true) {
            printf("--------------------\n");
            printf("1: Map              \n");
            printf("2: Inventory        \n");
            printf("3: Statistics       \n");
            printf("4: Shop             \n");
            printf("5: Work             \n");
            printf("6: Go home          \n");
            printf("#: Quit             \n");
            printf("--------------------\n");

            cin >> choice;
            if(choice == 1) {
                discoverMap(*mainCharacter, country);
            }
            if(choice == 3) {
                mainCharacter->showStatistics();
            }
            if(choice == 2){
                showInventory(*mainCharacter);
            }
            if(choice == 5){
                work(*mainCharacter);
            }
            if(choice == 6){
                relax(*mainCharacter);
            }
            if(choice == 4){
                shop(*mainCharacter);
            }
            if(choice == 0){
                exit(0);
            }
        }
    }








}
