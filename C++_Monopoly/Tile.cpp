#include "Tile.h"
#include <iostream>


Tile::Tile() {
    setLocation(-1);
    setDescription("default");
}

Tile::Tile(int loc, std::string desc) {
	setLocation(loc);
	setDescription(desc);
};

void Tile::action(Player &p) {}

int Tile::getLocation() {
	return location;
}

void Tile::setLocation(int loc) {
	location = loc;
}

std::string Tile::getDescription() {
	return description;
}

void Tile::setDescription(std::string desc) {
	description = desc;
}

void Tile::displayDetails() {
    std::cout<<getLocation()<<". "<<getDescription()<<std::endl;
}