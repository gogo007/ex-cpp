#include "player.h"
#include "fortstate.h"
#include "bonstate.h"
#include "moyenstate.h"
#include "faiblestate.h"
#include "mortstate.h"
#include <iostream>

Player::Player()
{
        srand((int)time(0));
    this->setLife(100);
    this->hisPseudo="Default";
    this->hisState=new FortState();
}
Player::~Player(){

}
Player::Player(std::string aPseudo)
{
    this->setLife(100);
    this->hisPseudo=aPseudo;
    this->hisState=new FortState();
}
std::string Player::getPseudo(){
    return this->hisPseudo;
}
void Player::setLife(int aHP){
    if(aHP<0){
        this->hisLife=0;
    }else if (aHP>=100){
        this->hisLife=100;
    }else{
     this->hisLife=aHP;
    }
    this->refreshState();// Refresh State with new HP
}
int Player::getLife(){
    return this->hisLife;
}
void Player::setState(State *aSt){
    this->hisState=aSt;
}
void Player::regen(){
    int regen = (hisState->regen());
    std::cout << "\nLe joueur " << this->getPseudo() <<" recupere "<< regen << " HP";
    this->setLife(hisLife+=regen); // Calculate random percent gain of health
}
State* Player::getState(){
    return hisState;
}
void Player::refreshState(){

    if(this->getLife()>=80) // 100 to 80
    {
        this->setState(new FortState());
    }else if(this->getLife()<80 && this->getLife()>=50)//79 to 50
        {
            this->setState(new BonState);
        }
        else if(this->getLife()<50 && this->getLife()>=30)//49 to 30
            {
                this->setState(new MoyenState);
            }
            else if(this->getLife()<30 && this->getLife()>0)//29 to 1
                {
                    this->setState(new FaibleState);
                }
                else{                                      // 0
                    this->setState(new MortState);
                    }
}
void Player::attack(Player *aP, int aPower){

    this->setLife(this->getLife()-aPower); // Remove health cost of the attack
    int thePowerAttack = this->hisState->attaquer(aPower); //calc power of attack , Call attack state depend
    aP->defend(thePowerAttack);
}
void Player::defend(int aPowerAttack){
    int theDamage = this->hisState->defendre(aPowerAttack);
    std::cout << "\nLe joueur "<< this->getPseudo() << " perd " << theDamage << " HP";
    this->setLife(this->getLife()-theDamage);
    std::cout << this->getLife();
}
