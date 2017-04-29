//
// Created by marc on 05/12/2016.
//

#ifndef TASK2_BLANK_H
#define TASK2_BLANK_H

#include "Tile.h"

class Blank : public Tile {
public:
    Blank(int, std::string);
    void action(Player &p);
};

#endif //TASK2_BLANK_H
