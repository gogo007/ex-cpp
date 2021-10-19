#ifndef _GAME_H
#define _GAME_H
#include "player.h"
#include <list>

//!
//! \file game.h
//! \brief Classe Mère Game
//! \author Hugo GABORIT IUT Info La Rochelle
//! \version 0.1
//! \date 25 Sept 2020
//!
//! Classe Mère contenant le main, la gestion de la partie, des tours, des Player.
//!
class Game {
  public:
//!
//! \brief Constructeur Game
//!
//! Méthode qui permet de créer une Game. Les étapes:
//! - Saisir le nombre de Player entre 3 et 10. (vérification incluse)
//! - Saisir les pseudos (ne prends pas en compte les pseudos composés, vérification qu'il existe déjà dans la liste)
//!
//! \param None
    
    Game();
//!
//! \brief Constructeur Game pour les tests
//!
//! Méthode qui permet de créer une Game dans un test, et qu'on veut un nombre de joueurs précis.
//! \param int nbPlayer : un nombre de joueurs, soit la taille de la liste.
//!
    Game(int nbPlayer);

//!
//! \brief Destructeur Game
//!
//! Méthode de détruire la Game en mémoire sans fuite.
//! - Parcours de la liste des Player afin d'appeler ~Player()
//!
//! \param None

    ~Game();

//!
//! \brief Fonction Main
//!
//! Fonction principale, qui contient l'appel du constructeur de Game, ainsi que la boucle de jeu.
//! \param None

    int main();

//!
//! \brief Méthode lancement du tirage
//!
//! Méthode qui permet aux Player de tenter leur chance pour récupérer de la vie à chaque fin de tour.
//! - Va parcourir la liste des Player, et appeler la méthode Player::regen();
//! \param None

    void tirage();

//!
//! \brief Méthode d'ajout de Player dans la Game
//!
//! Méthode qui permet d'ajouter un Player en vérifiant qu'il a bien été ajouté  à la liste.
//!
//! \param Player *, un Player à ajouter
//! \return booléen, si le Player est inséré dans la liste de la Game.

    bool addPlayer(Player * aP);

//!
//! \brief Méthode de vérification pour continuer la partie
//!
//! Méthode qui permet de vérifier qu'au moins deux Player ont en vie dans la Game
//! - Parcours de la liste des Players en vérifiant leurs points de vie.
//! \return booléen, si il y a au moins deux Player en vie.

    bool isContinue();

//!
//! \brief Méthode pour jouer un tour
//!
//! Méthode qui permet de choisir quel Player attaque quel Player.
//! - Chaque Player attaque deux Player
//! - Le player saisit la puissance de l'attaque entre 1 et 10
//! - va appeler la méthode Player::attack(Player *aP, int aPower)

    void playTour();

//!
//! \brief Méthode de recherche de Player dans une liste de Player.
//!
//! Méthode qui permet d'ajouter un Player en vérifiant qu'il a bien été ajouté  à la liste.
//!
//! \param Player *, un Player à rechercher
//! \return Player* , soit le Player, soit nullptr quand il n'y est pas.

    Player * searchPlayer(std::string aPseudo);

//!
//! \brief Méthode d'affichage des joueurs.
//!
//! Méthode qui affiche les pseudos et la vie associés aux Player.
//!
    
    void displayLifes();
//!
//! \brief Méthode d'accès à la liste des joueurs
//!
//! \return std::list<Player*>* , soit la liste des Player de la Game
//!
    std::list<Player*>* getPlayers();

  private:
    //!liste des Player
    std::list<Player *> * players;

};
#endif
