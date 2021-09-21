#include <iostream>
#include <thread>
#include "view/Application.h"
#include "model/entity/Country.h"

using namespace std;

void Thoughts(){
    string thoughts[5] = { "\nYou don't remember me? We spoke on the phone...I told you I would find you\n",
                           "\nThere Are Fates Worse Than Death!\n",
                           "\ni will find you, and i will kill you\n",
                           "\nlease understand... it was all business. It wasn't personal.\n",
                           "\nMom said your job made you paranoid\n"
    };
    srand( NULL);
    for(int i = 0; i<=5; i++){
        cout<<thoughts[rand()%4];
        this_thread::sleep_for(chrono::milliseconds(15000));
    }
}


Country setGeography(){
    Country Berland("Berland");
    Character Muha(70, "Nurmukhammed", 37, 150, 5);
    Character Raiko(75, "Rayimbek", 43, 250, 10);
    Character Altosh(50, "Altynbek", 50, 100, 3);
    Character Nurgiss(60, "Nurgisa", 40, 5050, 53);
    Character Tima(90, "Timur", 50, 0, 30);
    Character Gani(120, "Gani", 15, 2, 10);
    Character Adik(60, "Adilet", 35, 500, 7);
    Character Ilyas(65, "Ilyas", 45, 1500, 25);
    Character Duldiev(70, "Rayimbek", 30, 10000, 81);

    Muha.addtoInventory(*new Item("Knife", 150, 500));
    Raiko.addtoInventory(*new Item("Bic", 5, 15));
    Altosh.addtoInventory(*new Item("AWP", 415, 4750));
    Tima.addtoInventory(*new Item("he grenade", 150, 350));
    Gani.addtoInventory(*new Item("Laser sword", 1500, 30000));
    Adik.addtoInventory(*new Item("HE", 300, 800));
    Ilyas.addtoInventory(*new Item("Axe", 75, 150));
    Duldiev.addtoInventory(*new Item("Bow", 150, 350));

    City Amegakure("Amegakure");
    Amegakure.addCitizen(Muha);
    Amegakure.addCitizen(Nurgiss);
    Amegakure.addCitizen(Adik);

    City Bamboo("Bamboo");
    Bamboo.addCitizen(Altosh);
    Bamboo.addCitizen(Ilyas);
    Bamboo.addCitizen(Raiko);

    City Daidai("Daidai");
    Daidai.addCitizen(Gani);
    Daidai.addCitizen(Tima);
    Daidai.addCitizen(Duldiev);

    Berland.addCity(Daidai);
    Berland.addCity(Bamboo);
    Berland.addCity(Amegakure);

    return Berland;
}

int main() {

    thread th (Thoughts);
    th.detach();


    Application *app = new Application();

    Country Berland = setGeography();

    app->start(Berland);
}
