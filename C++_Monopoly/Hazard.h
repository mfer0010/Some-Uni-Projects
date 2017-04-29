//
// Created by marc on 05/12/2016.
//

#ifndef TASK2_HAZARD_H
#define TASK2_HAZARD_H

#include <string>
#include "Tile.h"
#include "Player.h"


class Hazard : public Tile {
private:
    int amountToCharge;

public:
    Hazard(int, std::string, int);
    void setAmountToCharge(int);
    int getAmountToCharge();
    void action(Player &p);
};

#endif //TASK2_HAZARD_H
