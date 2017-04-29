//
// Created by marc on 05/12/2016.
//

#ifndef TASK2_PORT_H
#define TASK2_PORT_H

#include "Ownerships.h"


class Port : public Ownerships {
public:
    Port(int loc, std::string desc, int pr, Player &p);
    int getCostOnLanding();
    void action(Player &p);
    void displayDetails();

private:
    int costOnLanding;
    void updateCharge(int);
};

#endif //TASK2_PORT_H
