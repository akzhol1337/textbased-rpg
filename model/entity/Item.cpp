#include "Item.h"
#include <iostream>

using namespace std;

void Item::showItem(int num) {
    cout << "#" << num << ": "<< item << "\n";
    printf("Damage: %d, Price: %d\n", damage, price);
    printf("---------------------\n");
}

Item::Item(const string &item, int damage, int price) : item(item), damage(damage), price(price) {}
