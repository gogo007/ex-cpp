#ifndef _STATE_H
#define _STATE_H

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
//!
//! \file state.h
//! \brief Classe Abstraite State
//! \author Hugo GABORIT IUT Info La Rochelle
//! \version 0.1
//! \date 25 Sept 2020
//!
//! Interface pour les états du Player.
//!
class State {
  public:
//!
//! \brief Constructeur
    
    State();

//!
//! \brief Destructeur
    
    ~State();

//!
//! \brief Calcul des dégats de l'attaque
//!
//! Methode qui permet de calculer les dégats en fonction de l'état de l'attaquant, et de la puissance envoyée.
//!
//! \param aPower : coût de l'attaque
//! \return Renvoit un entier qui correspond aux dégats à attribuer au joueur.

    virtual int attaquer(int aPower) = 0;

//!
//! \brief Calcul des dégats reçus de l'attaque
//!
//! Methode qui permet de calculer les dégats reçus en fonction de l'état du défenseur.
//!
//! \param aPower : dégats reçus
//! \return Renvoit un entier qui correspond aux dégats à infliger au défenseur.

    virtual int defendre(int aPower) = 0;

//!
//! \brief Calcul des points de vie à récupérer
//!
//! Methode qui permet de calculer les points de vie récupérés lors de l'appel du tirage.
//!
//! \return Renvoit un entier qui correspond aux points de vie à récupérer

    virtual int regen() = 0;

};
#endif
