//
// Created by marc on 05/12/2016.
//

#include "Xorti.h"
#include "GameController.h"
#include <iostream>
#include <ctime>

Xorti::Xorti(int loc, std::string desc) : Tile(loc, desc) {}

void Xorti::action(Player &p) {
    srand(time(NULL));
    int ref = rand() % 4 +1;
    int amount;

    switch (ref){
        case 1:
            amount = rand() %91 + 10;
            std::cout<<"It is your birthday, collect $"<<amount<<" from 2 other players"<<std::endl;
            //Problem in design... this function does not work as intented!! :/
            p.addToBalance(amount*2);
            break;
        case 2:
            amount = rand() %101 + 50;
            std::cout<<"You parked your car in a lecturer’s spot, and are therefore fined $"<<amount<<std::endl;
            p.addToBalance(-amount);
            //Note, for Simplicity, money is not placed in community parking
            break;
        case 3:
            amount = rand() % 141 + 40;
            std::cout<<"MEPA has fined you $"<<amount<<" for each of your buildings"<<std::endl;
            //Charge according to number of building owned:
            p.addToBalance(-(amount*p.getNumberOfHousesOwned()));
            std::cout<<p.getCharacter()<<" has payed a total of "<<amount*p.getNumberOfHousesOwned()<<std::endl;
            break;
        case 4:
            //Note, for simplicity assume player does not react to new location
            amount = rand() % 41;
            std::cout<<"Advance to position "<<amount<<std::endl;
            //if player lands on go, add $400, else if passes go, add $200
            if (amount == 0) {
                std::cout<<p.getCharacter()<<" has earned $400"<<std::endl;
                p.addToBalance(400);
            } else if (p.getPosition() >= amount) {
                std::cout<<p.getCharacter()<<" has passed go and earned $200"<<std::endl;
                p.addToBalance(200);
            }
            p.setPosition(amount);
    }

}

