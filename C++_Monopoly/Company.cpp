//
// Created by marc on 06/12/2016.
//


#include "Company.h"
#include <iostream>

Company::Company(int loc, std::string desc, int pr, Player &p) : Ownerships(loc,desc,pr,p) {
    setCostMultiplier();
}

int Company::getCostMultiplier() {
    return costMultiplier;
}

void Company::setCostMultiplier() {
    costMultiplier = 4;
    //if owner has other Company, set cost multiplier to 10
    if (getOwner().getNumberOfCompaniesOwned() == 2) {
        costMultiplier = 10;
    }
}

void Company::action(Player &p) {
    char actionListner;
    //bool error = false;
    if (getOwner().getCharacter().compare("bank")==0) { //if tile is owned by the bank:
        std::cout<<p.getCharacter()<<", would you like to buy the tile for $"<<getPrice()<<"? (Y/N)"<<std::endl;
        std::cin>>actionListner;
        if (actionListner== 'Y'|| actionListner=='y') {
            p.addToBalance(-getPrice());
            setOwner(p);
            p.setNumberOfCompaniesOwned((p.getNumberOfCompaniesOwned()+1));
            //setCostMultiplier();
            std::cout<<p.getCharacter()<<" now owns "<<getDescription()<<std::endl;
        } else {
            //auction
        }
    } else if (getOwner().getCharacter().compare(p.getCharacter())!=0) { //if tile is owed by another player
        setCostMultiplier(); //ensure cost multiplier is correct for all objects
        std::cout<<p.getCharacter()<<" must pay "<<getOwner().getCharacter()<<" "<<getCostMultiplier()<<" times their dice roll"<<std::endl;
        p.pay(getOwner(), getCostMultiplier() *p.getDiceRoll());
        std::cout<<p.getCharacter()<<" has payed "<<getOwner().getCharacter()<<" $"<<getCostMultiplier()*p.getDiceRoll()<<std::endl;
    }
}

void Company::displayDetails() {
    std::cout<<getLocation()<<". "<<getDescription()<<"\tOwned by "<<getOwner().getCharacter()<<std::endl;

}


