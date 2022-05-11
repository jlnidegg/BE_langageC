//
// Created by Jean-Louis Nidegger on 05/05/2022.
//

#ifndef BEC___SETUP_H
#define BEC___SETUP_H


class Setup { // La classe setup est la classe dite mère de notre projet :
    protected:// elle centralise les pins et les fréquences de baude, paramètres communs à tout les capteurs et actionneurs
    int pin;
    int frequency;
};

#endif //BEC___SETUP_H
