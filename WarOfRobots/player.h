#ifndef _PLAYER_H
#define _PLAYER_H
#include "state.h"

class State;

class Player {
  public:
//!
//! \brief Constructeur par défaut
//!
//! Constructeur qui créé un joueur dont le pseudo n'est pas passé en paramètre.
//! - Son pseudo sera "Default"
    
    Player();

//!
//! \brief Destructeur par défaut
//!
//! Destructeur par défaut
    
    ~Player();

//!
//! \brief Constructeur par avec le pseudo du Player
//!
//! Constructeur qui créé un joueur dont le pseudo est passé en paramètre.
//! - Son pseudo sera "Default"
//! \param std::string, le pseudo du joueur à créer.
    
    Player(std::string aPseudo);

//!
//! \brief Méthode pour récupérer de la vie selon le State.
//! Appelle la méthode regen du State actuel du joueur.
    
    void regen();

//!
//! \brief Méthode de définition de l'attribut vie.
//!
//!
//! \param int aHP, la Nouvelle vie.
    
    void setLife(int aHP);

//!
//! \brief Méthode d'accès aux points de vie du joueur.
//! \return int la vie actuelle du joueur
    
    int getLife();

//!
//! \brief Méthode de définition du State pour le Player
//! Méthode qui permet d'ajouter un Player en vérifiant qu'il a bien été ajouté  à la liste.
//! \param State* , un nouvel état pour le Player.

    void setState(State * aSt);

//!
//! \brief Méthode d'accès au type de State du Player
//! \return State* , l'état actuel du Player
    
    State * getState();

//!
//! \brief Méthode pour attaquer un Player.
//! Méthode qui permet d'attaquer un Player selon l'état du joueur.
//! Elle appelera à la fin Player::defendre(int aPowerAttack); lorsque la puissance sera déterminé selon le State du Player.
//! Le calcul selon l'état se fait dans State::attack(int aPower);
//! \param Player* , le joueur à attaquer, et le cout de l'attaque fournie
    
    void attack(Player * aP, int aPower);

//!
//! \brief Méthode pour défendre une attaque
//! Méthode qui permet de défendre une attaque
//! Le calcul selon l'état se fait dans State::defend(int aPower);
//! \param int l'attaque à défendre

    void defend(int aPowerAttack);

//!
//! \brief Méthode pour mettre à jour le State du Joueur
//! Méthode qui met à jour le State selon les points de vie.
//! Le calcul selon l'état se fait dans State::defend(int aPower);
    
    void refreshState();

//!
//! \brief Méthode pour accéder au pseudo du joueur
//!
//! \return std::string , le pseudo du joueur.
    
    std::string getPseudo();


  private:
    //!Pseudo du Player
    std::string hisPseudo;

    //!Vie du Player
    int hisLife;

    //!State du Player
    State * hisState;

};
#endif
