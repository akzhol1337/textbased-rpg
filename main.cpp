#include <iostream>
#include <thread>
#include "view/Application.h"
#include "model/entity/Country.h"

using namespace std;

void Thoughts(){
    string thoughts[5] = { "I haven't eaten in almost 8 hours.",
                           "I want to sleep.",
                           "However, it is cold today.",
                           "I will overcome enemies and become the strongest.",
                           "I ought to go to my parents somehow."};
    srand( time( 0 ) );
    for(size_t i = 0; i<=5; i++){
        cout<<"\n      -       \n"<<thoughts[rand()%4]<<"\n      -       \n";
        this_thread::sleep_for(chrono::milliseconds(15000));
    }
}


Country setGeography(){
    Country Berland("Berland");
    Character Muha(70, "Nurmukhammed", 37);
    Character Raiko(75, "Rayimbek", 43);
    Character Altosh(50, "Altynbek", 50);
    Character Nurgiss(60, "Nurgisa", 40);
    Character Tima(90, "Timur", 50);
    Character Gani(120, "Gani", 15);
    Character Adik(60, "Adilet", 35);
    Character Ilyas(65, "Ilyas", 45);
    Character Duldiev(70, "Rayimbek", 30);

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
