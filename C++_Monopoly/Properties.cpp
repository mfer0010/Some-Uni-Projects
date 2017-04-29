#include "Properties.h"
#include <iostream>
#include <string>

using namespace std;

Properties::Properties(int loc, string desc, int pr, Player &p, string col) : Ownerships(loc,desc,pr,p) {
	//super(loc, desc, pr, p);
	setColour(col);
	setNoOfHouses(0);
	updateCharge();
}

void Properties::action(Player &p) {
	char actionListner;
	//bool error = false;
	if (getOwner().getCharacter().compare("bank")==0) { //if tile is owned by the bank:
		cout<<"Would you like to buy the tile for $"<<getPrice()<<" (Y/N)"<<endl;
		cin>>actionListner;
		if (actionListner== 'Y'|| actionListner=='y') {
			p.addToBalance(-getPrice());
			setOwner(p);
            std::cout<<p.getCharacter()<<" now owns "<<getDescription()<<std::endl;
		} else {
			//auction
		}
	} else if (getOwner().getCharacter().compare(p.getCharacter())!=0) { //if tile is owed by another player
        std::cout<<p.getCharacter()<<" must pay "<<getOwner().getCharacter()<<" $"<<getCostOnLanding()<<std::endl;
		p.pay(getOwner(), costOnLanding);
	}
}

string Properties::getColour() {
	return colour;
}

void Properties::setColour(string col) {
	colour = col;
}

int Properties::getNoOfHouses() {
	return noOfHouses;
}

void Properties::setNoOfHouses(int amount) {
	noOfHouses = amount;
}

int Properties::getCostOnLanding() {
	return costOnLanding;
}

void Properties::displayDetails() {
    cout<<getLocation()<<". "<<getDescription()<<"\tColour: "<<getColour()<<",\tOwned by "<<getOwner().getCharacter()<<"\tHas "<<getNoOfHouses()<<" houses."<<endl;
}

void Properties::updateCharge() {
	if (colour.compare("brown")==0) {
		switch(noOfHouses) {
			case(0):
			costOnLanding = 4;
			break;
			case(1):
			costOnLanding = 20;
			break;
			case(2):
			costOnLanding = 60;
			break;
			case(3):
			costOnLanding = 180;
			break;
			case(4):
			costOnLanding = 320;
			break;
		}
	} else if (colour.compare("blue")==0) {
		switch(noOfHouses) {
			case(0):
			costOnLanding = 6;
			break;
			case(1):
			costOnLanding = 30;
			break;
			case(2):
			costOnLanding = 90;
			break;
			case(3):
			costOnLanding = 270;
			break;
			case(4):
			costOnLanding = 400;
			break;
		}
	} else if (colour.compare("pink")==0) {
		switch(noOfHouses) {
			case(0):
			costOnLanding = 10;
			break;
			case(1):
			costOnLanding = 50;
			break;
			case(2):
			costOnLanding = 150;
			break;
			case(3):
			costOnLanding = 450;
			break;
			case(4):
			costOnLanding = 625;
			break;
		}
	} else if (colour.compare("orange")==0) {
		switch(noOfHouses) {
			case(0):
			costOnLanding = 14;
			break;
			case(1):
			costOnLanding = 70;
			break;
			case(2):
			costOnLanding = 200;
			break;
			case(3):
			costOnLanding = 550;
			break;
			case(4):
			costOnLanding = 750;
			break;
		} 
	} else if (colour.compare("red")==0) {
		switch(noOfHouses) {
			case(0):
			costOnLanding = 18;
			break;
			case(1):
			costOnLanding = 90;
			break;
			case(2):
			costOnLanding = 250;
			break;
			case(3):
			costOnLanding = 700;
			break;
			case(4):
			costOnLanding = 875;
			break;
		}
	} else if (colour.compare("yellow")==0) {
		switch(noOfHouses) {
			case(0):
			costOnLanding = 22;
			break;
			case(1):
			costOnLanding = 110;
			break;
			case(2):
			costOnLanding = 330;
			break;
			case(3):
			costOnLanding = 800;
			break;
			case(4):
			costOnLanding = 975;
			break;
		}
	} else if (colour.compare("green")==0) {
		switch(noOfHouses) {
			case(0):
			costOnLanding = 26;
			break;
			case(1):
			costOnLanding = 130;
			break;
			case(2):
			costOnLanding = 390;
			break;
			case(3):
			costOnLanding = 900;
			break;
			case(4):
			costOnLanding = 1100;
			break;
		}
	} else if (colour.compare("darkBlue")==0) {
		switch(noOfHouses) {
			case(0):
			costOnLanding = 50;
			break;
			case(1):
			costOnLanding = 200;
			break;
			case(2):
			costOnLanding = 600;
			break;
			case(3):
			costOnLanding = 1400;
			break;
			case(4):
			costOnLanding = 1700;
			break;
		}
	}
}

