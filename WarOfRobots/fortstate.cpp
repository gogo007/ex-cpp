
#include "fortstate.h"

int FortState::attaquer(int aPower) {

    return (1.5*aPower);
}

int FortState::defendre(int aPowerAttack) {

    return (0.75*aPowerAttack);
}

int FortState::regen() {


    int theGain = rand()%10+1; // 10 possibilities
    switch (theGain) {
        case 1:
        case 2:
                theGain=10;break;//20% for 10HP
        case 3:
        case 4:
        case 5:
        case 6:
                theGain=5;break;//40% for 5HP
        default: theGain=0;break;//The rest

    }
    return theGain;
}

