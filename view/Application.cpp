#include "Application.h"
#include <iostream>

using namespace std;

void Application::start() {
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

    }

}
