
#include "bonstate.h"

int BonState::attaquer(int aPowerAttack) {

    return (1*aPowerAttack);
}

int BonState::defendre(int aPowerAttack) {

    return aPowerAttack;
}

int BonState::regen() {

    int theGain = rand()%10+1; // 10 possibilities
    switch (theGain) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
                theGain=5;break;//70% for 5HP
        default: theGain=0;break;//The rest

    }
    return theGain;
}

