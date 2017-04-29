#ifndef TASK2_TILE_H
#define TASK2_TILE_H

#include <string>
#include "Player.h"



class Tile {
public:
    Tile();
	Tile(int, std::string);
	//abstract method (how player will be affected on landing)
	//virtual void action(Player) = 0;
	//getters/setters:
	int getLocation();
	void setLocation(int);
	std::string getDescription();
	void setDescription(std::string);
    virtual void action (Player &p);
    virtual void displayDetails();

private:
	//variables:
	int location;
	std::string description;
	

};

#endif //TASK2_TILE_H