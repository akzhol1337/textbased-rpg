#include <string>

#ifndef TEXTBASED_RPG_ITEM_H
#define TEXTBASED_RPG_ITEM_H


class Item {
public:
    std::string item;
    int damage;
    int price;

    Item(const std::string &item, int damage, int price);

    void showItem(int num);
};


#endif //TEXTBASED_RPG_ITEM_H
