//
// Created by marc on 05/12/2016.
//

#ifndef TASK2_XORTI_H
#define TASK2_XORTI_H

#include "Tile.h"
#include "Player.h"
#include <string>

class Xorti : public Tile {
public:
    Xorti(int, std::string);
    void action(Player &p);
};

#endif //TASK2_XORTI_H
