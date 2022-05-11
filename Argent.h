//
// Created by Jean-Louis Nidegger on 05/05/2022.
//

#ifndef BEC___ARGENT_H
#define BEC___ARGENT_H
#include <Arduino.h>
#include <Micro.h> // pour le sum

/*********
 * La classe argent gère la valeur de l'argent en euros, dollars et yens que possède la Voiture pour payer le péage
*********/

template <typename T> class Argent {
        public:

        int dim = 3; // Il faut 3 euros pour passer le péage, donc 3 bip émis
        T * wallet ; // Création du portefeuille


        Argent(){                   // Constructeur de l'objet Argent, avec les 3 types de monnaies
            wallet = new T[dim];
            wallet[0] = rand() % 10; // euros
            wallet[1] = (rand() % 10)*1.05; // dollars
            wallet[2] = (rand() % 10)*136.98; // yens
        }

        Argent & operator += (int bip) { // Redéfinition de l'opérateur += afin de mettre à jour correctement 
            wallet[0] += bip;            // chaque type de monnaie dans le portefeuille
            wallet[1] += bip*1.05;
            wallet[2] += bip*136.98;
            return (*this);
        }

        Argent & operator -= (int bip) { // Redéfinition de l'opérateur -= afin de mettre à jour correctement 
            wallet[0] -= bip;            // chaque type de monnaie dans le portefeuille notamment lors du paiement
            wallet[1] -= bip*1.05;
            wallet[2] -= bip*136.98;
            return (*this);
        }

        T monMax2(T x, T y){     // 1ere fonction de comparaison pour obtenir la monnaie possédée en plus grande quantité
            return (x>y)? x : y; // entre 2 des 3 monnaies
        }

        T monMax3(T x, T y, T z){ // 2eme fonction de comparaison afin d'obtenir la monnaie possédée en plus grande quantité
            T aux;                // entre les 3 monnaies
            aux=monMax2(x,y);
            return monMax2(aux,z);
        }
    };





#endif //BEC___ARGENT_H
