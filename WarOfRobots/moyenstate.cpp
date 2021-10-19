
#include "moyenstate.h"

int MoyenState::attaquer(int aPowerAttack) {

    return (1*aPowerAttack);
}

int MoyenState::defendre(int aPowerAttack) {

    return (aPowerAttack);
}

int MoyenState::regen() {


    int theGain = rand()%10+1; // 10 possibilities
    switch (theGain) {
        case 1:
        case 2:
        case 3:
                theGain=10;break;//30% for 10HP
        case 4:
        case 5:
        case 6:
                theGain=5;break;//30% for 5HP
        default: theGain=0;break;//The rest

    }
    return theGain;
}

