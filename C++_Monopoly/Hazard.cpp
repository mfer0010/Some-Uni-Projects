//
// Created by marc on 05/12/2016.
//
#include "Hazard.h"
#include <iostream>

Hazard::Hazard(int loc, std::string desc, int amount) : Tile(loc, desc) {
    setAmountToCharge(amount);
}

void Hazard::setAmountToCharge(int amount) {
    amountToCharge = amount;
}

int Hazard::getAmountToCharge() {
    return amountToCharge;
}

void Hazard::action(Player &p) {
    std::cout<<p.getCharacter()<<" has lost"<< getAmountToCharge()<<" due to income tax charges"<<std::endl;
    p.addToBalance(-amountToCharge);
}

