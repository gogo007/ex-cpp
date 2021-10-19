#ifndef _FAIBLESTATE_H
#define _FAIBLESTATE_H


#include "state.h"

//!
//! \file faiblestate.h
//! \brief Classe concrète FaibleState
//! \author Hugo GABORIT IUT Info La Rochelle
//! \version 0.1
//! \date 25 Sept 2020
//!
//! Classe concrète représentant un état Faible pour la classe Player.
//!
class FaibleState : public State {
  public:
//!
//! \brief Calcul des dégats de l'attaque
//!
//! Méthode qui permet de calculer les dégats quand l'attaquant est de type FaibleState, et de la puissance envoyée.
//!
//! \param aPowerAttack : coût de l'attaque
//! \return Renvoit un entier qui correspond aux dégats à attribuer au joueur.

    int attaquer(int aPowerAttack) override;

//!
//! \brief Calcul des dégats reçus de l'attaque
//!
//! Methode qui permet de calculer les dégats reçus quand le défenseur est de type FaibleState.
//! La défense est multipliée par 1.5 par rapport à la puissance de départ (aPower)
//! \param aPowerAttack : dégats reçus
//! \return Renvoit un entier qui correspond aux dégats à infliger au défenseur.

    int defendre(int aPowerAttack) override;

//!
//! \brief Calcul des points de vie à récupérer
//!
//! Methode qui permet de calculer les points de vie récupérés lors de l'appel du tirage.
//! - Probabilité :
//!     - 10% : 20 points de vie gagnés
//!     - 10% : 10 points de vie gagnés
//!     - 10% : 5 points de vie gagnés
//! \param aPower : dégats à encaisser
//! \return Renvoit un entier qui correspond aux points de vie à récupérer

    int regen() override;

};
#endif
