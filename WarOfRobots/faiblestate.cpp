#include "faiblestate.h"

int FaibleState::attaquer(int aPowerAttack) {

    return (1*aPowerAttack);
}

int FaibleState::defendre(int aPowerAttack) {

    return (1.5*aPowerAttack);
}

int FaibleState::regen() {


    int theGain = rand()%10+1; // 10 possibilities
    switch (theGain) {
        case 1:
                theGain=20;break;//10% for 20HP
        case 2:
                theGain=10;break;//10% for 10HP
        case 3:
                theGain=5;break;//10% for 5HP
        default:
                theGain=0;break;//The rest

    }
    return theGain;
}

