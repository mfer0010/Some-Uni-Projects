//
// Created by marc on 05/12/2016.
//

#ifndef TASK2_TIPPARKJABXEJN_H
#define TASK2_TIPPARKJABXEJN_H

#include "Tile.h"
#include "Player.h"


class TipparkjaBXejn : public Tile {
public:
    TipparkjaBXejn(int, std::string);
    int getFund();
    void addToFund(int);
    void action(Player &p);

private:
    int fund;
    void initializeFund();

};

#endif //TASK2_TIPPARKJABXEJN_H
