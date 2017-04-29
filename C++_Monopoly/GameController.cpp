//
// Created by marc on 06/12/2016.
//

#include "GameController.h"
#include <iostream>
using namespace std;

GameController::GameController(int nOP) {
    bank = Player("bank", 0);
    setNoOfPlayers(nOP);
    activePlayers = new Player[nOP];
}

void GameController::setNoOfPlayers(int nOP) {
    noOfPlayers = nOP;
}

int GameController::getNoOfPlayers() {
    return noOfPlayers;
}

void GameController::initializeGameBoard() {
    gameBoard[0] = new Blank(0, "Go!");
    gameBoard[1] = new Properties(1, "L-Imsida", 60, bank, "brown");
    gameBoard[2] = new Xorti(2, "Xorti!");
    gameBoard[3] = new Properties(3, "Haz-Zabbar", 60, bank, "brown");
    gameBoard[4] = new Hazard(4, "Taxxa Interna", 200);
    gameBoard[5] = new Port(5, "Il-Port Tal-Imgarr", 200, bank);
    gameBoard[6] = new Properties(6, "Marsaskala", 100, bank, "blue");
    gameBoard[7] = new Xorti(7, "Xorti!");
    gameBoard[8] = new Properties(8, "Hal Qormi", 100, bank, "blue");
    gameBoard[9] = new Properties(9, "Marsaxlokk", 120, bank, "blue");
    gameBoard[10] = new Blank(10, "A street very close to a prison");
    gameBoard[11] = new Properties(11, "Il-Mosta", 140, bank, "pink");
    gameBoard[12] = new Company(12, "Tad-Dawl", 150, bank);
    gameBoard[13] = new Properties(13, "Birkirkara", 140, bank, "pink");
    gameBoard[14] = new Properties(14, "In-Naxxar", 160, bank, "pink");
    gameBoard[15] = new Port(15, "Ix-Xatt Tal-Belt", 200, bank);
    gameBoard[16] = new Properties(16, "Victoria", 180, bank, "orange");
    gameBoard[17] = new  Xorti(17, "Xorti!");
    gameBoard[18] = new Properties(18, "Haz-Zebbug", 180, bank, "orange");
    gameBoard[19] = new Properties(19, "Il-Birgu", 180, bank, "orange");
    gameBoard[20] = new TipparkjaBXejn(20, "Tipparkja B'Xejn!");
    gameBoard[21] = new Properties(21, "Il-Mellieha", 220, bank, "red");
    gameBoard[22] = new Xorti(22, "Xorti!");
    gameBoard[23] = new Properties(23, "Hal Gharghur", 220, bank, "red");
    gameBoard[24] = new Properties(24, "In-Nadur", 240, bank, "red");
    gameBoard[25] = new Port(25, "Ix-Xatt Tal-Kottonera", 200, bank);
    gameBoard[26] = new Properties(26, "San Giljan", 260, bank, "yelow");
    gameBoard[27] = new Properties(27, "Tas-Sliema", 260, bank, "yellow");
    gameBoard[28] = new Company(28, "Tal-Ilma", 150, bank);
    gameBoard[29] = new Properties(29, "Hal Balzan", 260, bank, "yellow");
    gameBoard[30] = new Blank(30, "A roadblock looking out for drunk drivers, good thing you don't drink!");
    gameBoard[31] = new Properties(31, "Portomaso", 300, bank, "green");
    gameBoard[32] = new Properties(32, "Tigne Point", 300, bank, "green");
    gameBoard[33] = new Xorti(33, "Xorti!");
    gameBoard[34] = new Properties(34, "Il-Wardija", 320, bank, "green");
    gameBoard[35] = new Port(35, "Il-Port Il-Kbir", 200, bank);
    gameBoard[36] = new Xorti(36, "Xorti");
    gameBoard[37] = new Properties(37, "Valletta", 350, bank, "darkBlue");
    gameBoard[38] = new Hazard(38, "Depozitu Fil-Bank", 100);
    gameBoard[39] = new Properties(39, "L-Imdina", 400, bank, "darkBlue");
}

void GameController::initializePlayers() {
    int actionListner;
    string characterList [10];
    int i, x;
    bool cont;
    bool error;

    //initialize character list
    characterList[0] = "hat";
    characterList[1] = "shoe";
    characterList[2] = "car";
    characterList[3] = "dog";
    characterList[4] = "horse";
    characterList[5] = "iron";
    characterList[6] = "ship";
    characterList[7] = "wheelbarrow";
    characterList[8] = "cannon";
    characterList[9] = "c++ developer";

    //list all characters
    cout<<"List of Characters:"<<endl;
    for (i = 0; i < 10; i++) {
        cout<<(i+1)<<". "<<characterList[i]<<endl;
    }

    //main loop to ask players to choose character
    i = 0;
    while (i < noOfPlayers) {
        cont = false;
        cout << "Player " << (i + 1) << " choose your character:" << endl;
        while (!cont) {
            cin >> actionListner;
            error = false;

            //check if character is already chosen:
            for (x = 0; x < i; x++) {
                //if Other player's character is the same as chosen character:
                if (activePlayers[x].getCharacter().compare(characterList[(actionListner - 1)]) == 0) {
                    error = true;
                }
            }
            if (error) {
                //player choose character again
                cout << "Character already chosen, please choose a different character" << endl;
            } else {
                activePlayers[i] = Player(characterList[(actionListner-1)], 1500);
                cont = true;
            }
        }
        i++;
    }
}

void GameController::loadGame() {
    cout<<"Initializing Game Board"<<endl;
    initializeGameBoard();
    cout<<"***********************"<<endl;
    cout<<"Initializing Players"<<endl;
    initializePlayers();
    cout<<"***********************"<<endl;
    //clear terminal the crude way:
    for (int i = 0; i < 10; i++) {
        printf("\n\n\n\n\n\n\n\n\n\n");
    }
    cout<<"Welcome to MonOOPoly!"<<endl;
}


/*void GameController::displayActivePlayers() {
    for (int i=0; i < getNoOfPlayers(); i++) {
        cout<<activePlayers[i].getCharacter()<<" has balance: $"<<activePlayers[i].checkBalance()<<endl;
    }
}*/

void GameController::displayPlayerLocation(Player &p) {
    cout<<p.getCharacter()<<" is on tile "<<p.getPosition()<<endl;
    gameBoard[p.getPosition()]->displayDetails();
}

int GameController::rollDice() {
    //based on probability distribution of rolling 2 dice
    //reference: http://mathinsight.org/image/two_dice_distribution
    srand(time(NULL));
    double value;
    value = ((double) rand() / RAND_MAX); // value ~ UNIF(0,1)
    //cout<<"value: "<<value<<endl;
    if (value < 0.0278) {
        return 2;
    } else if (value < 0.0833) { //1/36 + 1/18
        return 3;
    } else if (value < 0.1667) { // 1/36 + 1/18 + 1/12 ,etc...
        return 4;
    } else if (value < 0.2778) {
        return 5;
    } else if (value < 0.4167) {
        return 6;
    } else if (value < 0.5833) {
        return 7;
    } else if (value < 0.7222) {
        return 8;
    } else if (value < 0.8333) {
        return 9;
    } else if (value < 0.9167) {
        return 10;
    } else if (value < 0.9722) {
        return 11;
    } else {
        return 12;
    }
}

int GameController::movePlayer(int id, int paces) {
    int newLocation, initialLocation;
    initialLocation = activePlayers[id].getPosition();
    newLocation = (initialLocation + paces) % 40;
    activePlayers[id].setPosition(newLocation);
    cout<<activePlayers[id].getCharacter()<<" has moved to location "<<newLocation<<endl;
    //if Player lands on go, give 400, else if player passes go, give 200
    if (newLocation == 0) {
        cout<<activePlayers[id].getCharacter()<<" has earned $400"<<endl;
        activePlayers[id].addToBalance(400);
    } else if (newLocation < initialLocation) {
        cout<<activePlayers[id].getCharacter()<<" has passed go and earned $200"<<endl;
        activePlayers[id].addToBalance(400);
    }
    return newLocation;
}

bool GameController::kickOutPlayer(int id) {
    int cntr = 0;
    Player inActive("NULL", -1);
    cout<<"Player "<<id<<" kicked out of game"<<endl;
    activePlayers[id] = inActive;
    for (int i = 0; i < noOfPlayers; i++) {
        if (activePlayers[i].getCharacter().compare("NULL") != 0)
            cntr++;
    }
    if(cntr <= 1) {
        return true;
    }
    return false;
}

void GameController::displayBoard() {
    for (int i = 0; i < 40; i++) {
        gameBoard[i]->displayDetails();
        cout<<"\n";
    }
}

bool GameController::turn(int id, GameController &gc) {
    //if player is kicked out, skip player:
    if (activePlayers[id].getCharacter().compare("NULL") == 0) {
        return false;
    }

    int actionListner = 0;
    int paces, newLocation;
    bool proceed = false;
    bool error;
    string cont;
    cin.exceptions(ios_base::failbit);

    //Pre-Turn Loop:
    while (!proceed) {
        //clear terminal the crude way:
        /*for (int i = 0; i < 10; i++) {
            printf("\n\n\n\n\n\n\n\n\n\n");
        }*/
        do {
            try {
                error = false;
                cout << activePlayers[id].getCharacter() << "'s turn:" << endl;
                cout << "Pre Turn: " << endl;
                cout << "Choose an option" << endl;
                cout << "1. Buy House" << endl;
                cout << "2. Trade" << endl;
                cout << "3. Check Balance" << endl;
                cout << "4. Display Board" << endl;
                cout << "5. Show Position" << endl;
                cout << "6. Roll Dice" << endl;
                cout << "7. Quit Game" << endl;
                cin >> actionListner;
            } catch (const ios_base::failure& e) {
                error = true;
            }
        } while (error);

        switch (actionListner) {
            case 1:
                cout<<"Buy House, Work in Progress"<<endl;
                break;
            case 2:
                cout<<"Trade, Work in Progress"<<endl;
                break;
            case 3:
                cout<<activePlayers[id].getCharacter()<<" has balance: $"<<activePlayers[id].checkBalance()<<endl;
                cout<<"Enter c to continue"<<endl;
                cin>>cont;
                break;
            case 4:
                displayBoard();
                break;
            case 5:
                displayPlayerLocation(activePlayers[id]);
                break;
            case 6:
                //exit Pre-Turn, move on to Turn
                proceed = true;
                break;
            case 7:
                //Quit Game
                return true;
            default:
                break;
        }
    }

    //Turn:
    paces = rollDice();
    activePlayers[id].setDiceRoll(paces); //could be improved for functionality if placed in method
    cout<<"Dice was rolled"<<endl;
    cout<<"Value: "<<paces<<endl;
    newLocation = movePlayer(id, paces);
    cout<<activePlayers[id].getCharacter()<<" has landed on "<<gameBoard[newLocation]->getDescription()<<endl;
    gameBoard[newLocation]->action(activePlayers[id]); //method will be overwritten

    //Post Turn:
    if (activePlayers[id].checkBalance() < 0) {
        cout<<activePlayers[id].getCharacter()<<" is out of money, and has been kicked out of the game"<<endl;
        cout<<"Enter c to continue"<<endl;
        cin>>cont;
        return kickOutPlayer(id);
    }


    return false;
}