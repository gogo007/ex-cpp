#include <iostream>
#include "game.h"
#include "player.h"

Game::Game() {
    int nbJ=0;
    srand((int)time(nullptr));
    std::string inputChars;
    while(nbJ<3 || nbJ>10){
        std::cout << "Nombre de Joueurs(3 à 10): ";
        std::cin>>inputChars;std::cin.ignore();
        sscanf(inputChars.c_str(),"%d",&nbJ);
    }
    this->players = new std::list<Player *>();
        for(int i=0;i<nbJ;i++)
        {
            std::cout << "Pseudo du Joueur "<< i+1 <<": ";
            std::string pseudo;
            std::cin>>pseudo;std::cin.ignore();
            std::cout << '\n';
            if(this->searchPlayer(pseudo)==nullptr){
                if(!this->addPlayer(new Player(pseudo))) i--;// Restart input
            }else {
                std::cout<<"Joueur deja existant !\n";
                i--;
            }
        }
}
//Only for TEST
/*
Game::Game(int nbJ){
    srand((int)time(0));
    while(nbJ<3){
        std::cout << "Nombre de Joueurs(3 à 10): ";
        std::cin>>nbJ;std::cin.ignore();
    }
    this->players = new std::list<Player *>();
    this->players->resize(nbJ);
}
*/
Game::~Game() {

    //destroy element of list before
    for(Player * p : *players)
    {
        delete p; // call Player destructor to destroy current state
    }
    delete players;
}

void Game::tirage() {
    std::cout << "Regen des joueurs ! \n";
    for(Player * p : *players)
    {
        p->regen();
    }
}

bool Game::addPlayer(Player *aP) {

    int sizeBefore=players->size();
    players->push_back(aP);
    if(sizeBefore==(int)players->size()){
        return false;
    }else
    return true;
}

bool Game::isContinue() {

    std::list<Player *>::iterator it= players->begin();
    int nbInLife=0;
    Player pTemp;
    Player pInLive;
    for(;it!=players->end()&&nbInLife<2 ;it++){
        pTemp = **it;
        if(pTemp.getLife()!=0)
        {
            nbInLife++;
            if(nbInLife<2){
                pInLive = **it;
            }else pTemp = **it;
        }
    }
    bool res=(nbInLife>=2);
    if(!res){
        std::cout << "\nFIN DE LA PARTIE, LE JOUEUR " << pInLive.getPseudo() << " A GAGNE !!!";
    }
    return res;
}

void Game::playTour() {
    std::string inputchars="";
    for(Player *p : *players)
    {
        std::string firstPseudoToAtk;
        std::string secPseudoToAtk;
        int firstPowAtk=0;
        int secPowAtk=0;
        if(p->getLife()>0){
            std::cout << "\nC'est au tour du joueur " << p->getPseudo()<<'\n';
            std::cout << "Pseudo du premier joueur à attaquer: "; std::cin>>firstPseudoToAtk; std::cin.ignore();

            while(firstPowAtk<1 || firstPowAtk>10)
            {
                std::cout << "\nPuissance de la premiere attaque(1-10): "; std::cin>>inputchars; std::cin.ignore();
                sscanf(inputchars.c_str(),"%d",&firstPowAtk);
            }
            if(this->searchPlayer(firstPseudoToAtk)!=nullptr && firstPowAtk>0 && firstPowAtk<11)
            {
                std::cout << "\nLe joueur " << p->getPseudo()<<" lance une premiere attaque de " << firstPowAtk << " sur le joueur " << this->searchPlayer(firstPseudoToAtk)->getPseudo() <<"\n";
                p->attack(this->searchPlayer(firstPseudoToAtk), firstPowAtk);
            }
            this->displayLifes();
            if(p->getLife()>0){
                std::cout << "Pseudo du deuxieme joueur à attaquer: "; std::cin>>secPseudoToAtk; std::cin.ignore();
                while(secPowAtk<1 || secPowAtk>10)
                {
                    std::cout << "\nPuissance de la deuxieme attaque(1-10): "; std::cin>>inputchars; std::cin.ignore();
                    sscanf(inputchars.c_str(),"%d",&secPowAtk);
                }
                if(this->searchPlayer(secPseudoToAtk)!=nullptr && secPowAtk>0 && secPowAtk<11)
                {
                    std::cout << "\nLe joueur " << p->getPseudo()<<" lance une seconde attaque de " << firstPowAtk << " sur le joueur " << this->searchPlayer(firstPseudoToAtk)->getPseudo() <<"\n";
                    p->attack(this->searchPlayer(secPseudoToAtk), secPowAtk);
                }
            }
            std::cout<<"\n\n========FIN DU JOUEUR "<< p->getPseudo() << "=========\n";
            this->tirage();
            this->displayLifes();
        }
    }
    std::cout<<"\n==============================FIN DU TOUR=====================================";
}

Player * Game::searchPlayer(std::string aPseudo) {

    for(Player * p : *players)
    {
        if(p->getPseudo()==aPseudo)return p;
    }
    return nullptr;
}

void Game::displayLifes() {

    for(Player * p : *players)
    {
        std::cout << "\n" <<  p->getPseudo() << ": ";
        if(p->getLife()==0) std::cout <<"MORT";
        else std::cout << p->getLife();
    }
    std::cout << "\n\n";
}

std::list<Player*>* Game::getPlayers(){
return this->players;
}

