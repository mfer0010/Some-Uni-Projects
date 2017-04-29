#include "GameController.h"
#include <iostream>

using namespace std;
int main () {
    bool quit = false; //for menu
    bool endGame = false; //for Game
    bool error;
    string cont;
    int mainMenuActionListner;
    //for user input exception handling:
    cin.exceptions(ios_base::failbit);

    //settings variables
    int numberOfPlayers = 2; //default value

    //game controller:
    GameController gc(numberOfPlayers);
    int playerTurn = 0;

    while (!quit) {

        do {
            try {
                error = false;
                //clear screen:
                for (int i = 0; i < 10; i++) {
                    printf("\n\n\n\n\n\n\n\n\n\n");
                }
                cout << "Welcome to MonOOPoly" << endl;
                cout << "By Marc Ferriggi" << endl;
                //Display Menu:
                cout << "Choose an option:" << endl;
                cout << "1. New Game" << endl;
                cout << "2. Options (Beta)" << endl;
                cout << "3. Quit" << endl;
                cin >> mainMenuActionListner;
            } catch (const ios_base::failure& e) {
                error = true;
            }
        } while (error);

        //menu switch statement:
        switch(mainMenuActionListner) {
            case 1:
                gc.loadGame();
                //gc.displayGameBoard();
                //gc.displayActivePlayers();
                //cin>>cont;

                while (!endGame) {
                    endGame = gc.turn(playerTurn, gc);
                    playerTurn = (playerTurn + 1);
                    if (playerTurn >= numberOfPlayers)
                        playerTurn = 0;
                }
                break;
            case 2:
                cout<<"Options (Beta)"<<endl;
                cin>>cont;
                break;
            case 3:
                cout<<"Thanks for Playing!"<<endl;
                quit = true;
                break;
            default:
                break;
        }
    }

	return 0;
};