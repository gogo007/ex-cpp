#ifndef _MOYENSTATE_H
#define _MOYENSTATE_H


#include "state.h"

//!
//! \file moyenstate.h
//! \brief Classe concrète MoyenState
//! \author Hugo GABORIT IUT Info La Rochelle
//! \version 0.1
//! \date 25 Sept 2020
//!
//! Classe concrète représentant un état Moyen pour la classe Player.
//!
class MoyenState : public State {
  public:
//!
//! \brief Calcul des dégats de l'attaque
//!
//! Méthode qui permet de calculer les dégats quand l'attaquant est de type MoyenState, et de la puissance envoyée.
//! \param aPower : coût de l'attaque
//! \return Renvoit un entier qui correspond aux dégats à attribuer au joueur.

    int attaquer(int aPowerAttack) override;

//!
//! \brief Calcul des dégats reçus de l'attaque
//!
//! Methode qui permet de calculer les dégats reçus quand le défenseur est de type MoyenState.
//! \param aPower : dégats reçus
//! \return Renvoit un entier qui correspond aux dégats à infliger au défenseur.

    int defendre(int aPowerAttack) override;

//!
//! \brief Calcul des points de vie à récupérer
//!
//! Methode qui permet de calculer les points de vie récupérés lors de l'appel du tirage.
//! - Probabilité :
//!     - 30% : 10 points de vie gagnés
//!     - 30% : 5 points de vie gagnés
//! \param aPower : dégats à encaisser
//! \return Renvoit un entier qui correspond aux points de vie à récupérer

    int regen() override;

};
#endif
