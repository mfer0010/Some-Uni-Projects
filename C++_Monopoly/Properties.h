#ifndef TASK2_PROPERTIES_H
#define TASK2_PROPERTIES_H

#include <string>
#include "Ownerships.h"


class Properties final : public Ownerships {
public:

    Properties(int loc, std::string desc, int pr, Player &p, std::string col);

    //Polymorphism:
	void action(Player &p);
	//setters/getters
	std::string getColour();
	void setColour(std::string);
	int getNoOfHouses();
	void setNoOfHouses(int);
	int getCostOnLanding();
	void displayDetails();

private:
	std::string colour;
	int noOfHouses;
	int costOnLanding;
	void updateCharge(); //to be called initially and everytime a house is bought
};

#endif //TASK2_PROPERTIES_H