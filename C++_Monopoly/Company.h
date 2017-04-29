//
// Created by marc on 06/12/2016.
//

#ifndef TASK2_COMPANY_H
#define TASK2_COMPANY_H

#include "Ownerships.h"


class Company : public Ownerships {
public:
    Company(int loc, std::string desc, int pr, Player &p);
    void action(Player &p);
    int getCostMultiplier();
    void setCostMultiplier();
    void displayDetails();

private:
    int costMultiplier;
};

#endif //TASK2_COMPANY_H
