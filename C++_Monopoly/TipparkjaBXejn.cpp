//
// Created by marc on 05/12/2016.
//

#include "TipparkjaBXejn.h"
#include <iostream>

TipparkjaBXejn::TipparkjaBXejn(int loc, std::string desc) : Tile(loc,desc) {
    initializeFund();
}

int TipparkjaBXejn::getFund() {
    return fund;
}

void TipparkjaBXejn::initializeFund() {
    fund = 0;
}

void TipparkjaBXejn::addToFund(int amount) {
    fund += amount;
}

void TipparkjaBXejn::action(Player &p) {
    std::cout<<p.getCharacter()<<" has received $"<<fund<<std::endl;
    p.addToBalance(getFund());
    initializeFund();
}