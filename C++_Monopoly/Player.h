#ifndef TASK2_PLAYER_H
#define TASK2_PLAYER_H

#include <string>
#include <vector>


class Player {
public:
	//constructor:
	//charactr, balance
    Player();
	Player(std::string, int);
	//Getters/ Setters:
	//int getBalance(); Done in private as checkBalance();
	void setBalance(int);//amount
	std::string getCharacter();
	void setCharacter(std::string);//name
	int getPosition();
	void setPosition(int);//location
	void pay(Player, int); //target, amount
    int checkBalance();
    void addToBalance(int);//amount
    int getNumberOfCompaniesOwned();
    void setNumberOfCompaniesOwned(int);
    int getDiceRoll();
    void setDiceRoll(int);
    int getNumberOfPortsOwned();
    void setNumberOfPortsOwned(int);
    int getNumberOfHousesOwned();
    void setNumberOfHousesOwned(int);



private:
	//variables:
	std::string character;
	int balance;
	int position;
    int numberOfCompaniesOwned;
    int numberOfPortsOwned;
    int diceRoll;
    int numberOfHousesOwned;
	//functions:

	//void listProperties();		TODO
	void move(int); //no of paces

};

#endif //TASK2_PLAYER_H