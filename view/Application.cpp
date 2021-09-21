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

    exploreCity(mainCharacter, cities[choice]);
}

void Fight(Character &mainCharacter, Character &enemyCharacter){
    bool win = mainCharacter.fight(enemyCharacter);
    printf("********************************\n");

    printf("* Welcome to battle field\n");
    printf("       ////^\\\\\\\\\n"
           "      | ^   ^ |\n"
           "     @ (o) (o) @\n"
           "      |   <   |\n"
           "      |  ___  |\n"
           "       \\_____/\n"
           "     ____|  |____\n"
           "    /    \\__/    \\\n"
           "   /              \\\n"
           "  /\\_/|        |\\_/\\\n"
           " / /  |        |  \\ \\\n"
           "( <   |        |   > )\n"
           " \\ \\  |        |  / /\n"
           "  \\ \\ |________| / /\n"
           "   \\ \\|\n"
           "             \n"
           "___  ________\n"
           "\\  \\/ /  ___/\n"
           " \\   /\\___ \\ \n"
           "  \\_//____  >\n"
           "          \\/\n "
           "                 ,#####,\n"
           "                 #_   _#\n"
           "                 |a` `a|\n"
           "                 |  u  |\n"
           "                 \\  =  /\n"
           "                 |\\___/|\n"
           "        ___ ____/:     :\\____ ___\n"
           "      .'   `.-===-\\   /-===-.`   '.\n"
           "     /      .-\"\"\"\"\"-.-\"\"\"\"\"-.      \\\n"
           "    /'             =:=             '\\\n"
           "  .'  ' .:    o   -=:=-   o    :. '  `.\n"
           "  (.'   /'. '-.....-'-.....-' .'\\   '.)\n"
           "  /' ._/   \".     --:--     .\"   \\_. '\\\n"
           " |  .'|      \".  ---:---  .\"      |'.  |\n"
           " |  : |       |  ---:---  |       | :  |\n"
           "  \\ : |       |_____._____|       | : /\n"
           "  /   (       |----|------|       )   \\\n"
           " /... .|      |    |      |      |. ...\\\n"
           "|::::/'' jgs /     |       \\     ''\\::::|\n"
           "'\"\"\"\"       /'    .L_      `\\       \"\"\"\"'\n"
           "           /'-.,__/` `\\__..-'\\\n"
           "          ;      /     \\      ;\n"
           "          :     /       \\     |\n"
           "          |    /         \\.   |\n"
           "          |`../           |  ,/\n"
           "          ( _ )           |  _)\n"
           "          |   |           |   |\n"
           "          |___|           \\___|\n"
           "          :===|            |==|\n"
           "           \\  /            |__|\n"
           "           /\\/\\           /\"\"\"`8.__\n"
           "           |oo|           \\__.//___)\n"
           "           |==|\n"
           "           \\__/\n");

    printf("*****************************\n");
    if(win) {

        mainCharacter.gold += enemyCharacter.gold;
        mainCharacter.level += enemyCharacter.level;

        printf("\n\nCongratz, you win!!!!\n");
        printf("You gain: %d levels, %d gold\n", enemyCharacter.level, enemyCharacter.gold);
        printf("His inventory :\n");

        int num = 0;

        for(auto &to : enemyCharacter.getInventory()){
            cout << "#" << num << ": " << to.item << ", damage: " << to.weight << "\n";
        }

        printf("Input a item to choose, -1 to return\n");
        int choice;
        cin >> choice;
        if(choice == -1)
            return;
        mainCharacter.addtoInventory(enemyCharacter.getInventoryById(choice));
    } else {
        printf("\n\nLose\n");
    }
}

void Application::exploreCity(Character &mainCharacter, City &city) {
    cout << "------------------------------------------------------------\n\n";
    cout << "Welcome to " << city.title << "\n";
    printf("We have %d citizens in our city\n\n", (int)city.citizens.size());

    int num = 0;
    for(Character &character : city.citizens){
        num++;
        character.showCharacter(num);
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
