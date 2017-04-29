#include "Player.h"

Player::Player() {
	setCharacter("default");
	setBalance(0);
	setPosition(0);
    setNumberOfCompaniesOwned(0);
    setDiceRoll(0);
	setNumberOfHousesOwned(0);
	setNumberOfPortsOwned(0);
}

Player::Player(std::string c, int bal) {
	setCharacter(c);
	setBalance(bal);
	setPosition(0);
	setNumberOfCompaniesOwned(0);
    setDiceRoll(0);
    setNumberOfHousesOwned(0);
    setNumberOfPortsOwned(0);
}

void Player::setBalance(int amount) {
	balance = amount;
}

std::string Player::getCharacter() {
	return character;
}

void Player::setCharacter(std::string c) {
	character = c;
}

int Player::getPosition() {
	return position;
}

void Player::setPosition(int location) {
	position = location;
}

void Player::setNumberOfCompaniesOwned(int num) {
    numberOfCompaniesOwned = num;
}

int Player::getNumberOfCompaniesOwned() {
    return numberOfCompaniesOwned;
}

void Player::setDiceRoll(int num) {
    diceRoll = num;
}

int Player::getDiceRoll() {
    return diceRoll;
}

void Player::setNumberOfPortsOwned(int num) {
    numberOfPortsOwned = num;
}

int Player::getNumberOfPortsOwned() {
    return numberOfPortsOwned;
}

void Player::setNumberOfHousesOwned(int num) {
    numberOfHousesOwned = num;
}

int Player::getNumberOfHousesOwned() {
    return numberOfHousesOwned;
}

int Player::checkBalance() {
	return balance;
}

void Player::move(int amount) {
	int newPosition = (getPosition()+amount)%40;
	setPosition(newPosition);
}

void Player::pay(Player target, int amount) {
	target.addToBalance(amount);
	addToBalance(-amount);
}

void Player::addToBalance(int amount) {
	setBalance(checkBalance()+amount);
}
