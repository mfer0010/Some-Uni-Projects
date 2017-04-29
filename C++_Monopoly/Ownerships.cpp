#include "Ownerships.h"
#include <iostream>

Ownerships::Ownerships(int loc, std::string desc, int pr, Player &p) :Tile(loc, desc) {
	//super(loc, desc);
	setPrice(pr);
	setOwner(p);
}

//virtual void Ownerships::action(Player p) = 0;

int Ownerships::getPrice() {
	return price;
}

void Ownerships::setPrice(int amount) {
	price = amount;
}

Player Ownerships::getOwner() {
	return owner;
}

void Ownerships::setOwner(Player p) {
	owner = p;
}

void Ownerships::displayDetails() {
    std::cout<<"Should never be run"<<std::endl;
}