//
// Created by marc on 06/12/2016.
//

#ifndef TASK2_GAMECONTROLLER_H
#define TASK2_GAMECONTROLLER_H

//#include "Tile.h"
#include "Properties.h"
#include "Port.h"
#include "Company.h"
#include "Hazard.h"
#include "Xorti.h"
#include "TipparkjaBXejn.h"
#include "Blank.h"
#include "Player.h"

class GameController {
public:
    GameController(int);
    void setNoOfPlayers(int);
    int getNoOfPlayers();
    Tile *gameBoard[40];
    //Tile *ptrGameBoard[40];
    Player *activePlayers;
    Player bank;
    void loadGame();
   // void displayGameBoard();
    //void displayActivePlayers();
    bool kickOutPlayer(int);
    bool turn(int, GameController &gc);
    int rollDice();
    int movePlayer(int, int);
    void displayPlayerLocation(Player &p);


private:
    void initializeGameBoard();
    void initializePlayers();
    void displayBoard();
    int noOfPlayers;
};

#endif //TASK2_GAMECONTROLLER_H
