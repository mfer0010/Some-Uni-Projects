#ifndef TASK2_OWNERSHIPS_H
#define TASK2_OWNERSHIPS_H

#include <string>
#include "Tile.h"
#include "Player.h"


class Ownerships: public Tile {
public:
    Ownerships(int loc, std::string desc, int pr, Player &p);
	//polymorphism:
	virtual void action(Player &p) = 0;
	//getters/setters
	int getPrice();
	void setPrice(int);
	Player getOwner();
	void setOwner(Player);
	void displayDetails();

private:
	int price;
	Player owner;
};

#endif //TASK2_OWNERSHIPS_H