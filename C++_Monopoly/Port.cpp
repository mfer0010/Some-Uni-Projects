//
// Created by marc on 05/12/2016.
//

#include "Port.h"
#include <iostream>

Port::Port(int loc, std::string desc, int pr, Player &p) : Ownerships(loc,desc,pr,p) {
    updateCharge(1);
}

int Port::getCostOnLanding() {
    return costOnLanding;
}

void Port::updateCharge(int num) {
    switch (num) {
        case 1:
            costOnLanding = 25;
            break;
        case 2:
            costOnLanding = 50;
            break;
        case 3:
            costOnLanding = 100;
            break;
        case 4:
            costOnLanding = 200;
            break;
    }

}

void Port::action(Player &p) {
    char actionListner;
    //bool error = false;
    if (getOwner().getCharacter().compare("bank")==0) { //if tile is owned by the bank:
        std::cout<<p.getCharacter()<<", would you like to buy the tile for $"<<getPrice()<<"? (Y/N)"<<std::endl;
        std::cin>>actionListner;
        if (actionListner== 'Y'|| actionListner=='y') {
            p.addToBalance(-getPrice());
            setOwner(p);
            p.setNumberOfPortsOwned((p.getNumberOfPortsOwned()+1));
            //updateCharge(p.getNumberOfPortsOwned());
            std::cout<<p.getCharacter()<<" now owns "<<getDescription()<<std::endl;
        } else {
            //auction
        }
    } else if (getOwner().getCharacter().compare(p.getCharacter())!=0) { //if tile is owed by another player
        updateCharge(getOwner().getNumberOfPortsOwned()); //make sure charege is correct
        std::cout<<p.getCharacter()<<" must pay "<<getOwner().getCharacter()<<" $"<<getCostOnLanding()<<std::endl;
        p.pay(getOwner(), getCostOnLanding());
    }
}

void Port::displayDetails() {
    std::cout<<getLocation()<<". "<<getDescription()<<"\tOwned by "<<getOwner().getCharacter()<<std::endl;

}