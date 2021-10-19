#ifndef _MORTSTATE_H
#define _MORTSTATE_H


#include "state.h"

class MortState : public State {
  public:
//!
//! \brief Calcul des dégats de l'attaque
//!
//! Méthode qui permet de calculer les dégats quand l'attaquant est de type MortState, et de la puissance envoyée.
//! L'attaque est multipliée par 0 par rapport à la puissance de départ (aPower)
//! \param aPower : coût de l'attaque
//! \return Renvoit un entier 0

    int attaquer(int aPowerAttack) override;

//!
//! \brief Calcul des dégats reçus de l'attaque
//!
//! Methode qui permet de calculer les dégats reçus quand le défenseur est de type MortState.
//! La défense est multipliée par 0 par rapport à la puissance de départ (aPower)
//! \param aPower : dégats reçus
//! \return Renvoit un entier 0

    int defendre(int aPowerAttack) override;

//!
//! \brief Calcul des points de vie à récupérer
//!
//! Methode qui permet de calculer les points de vie récupérés lors de l'appel du tirage.
//! \param aPower : dégats à encaisser
//! \return Renvoit un entier 0

    int regen() override;

};
#endif
