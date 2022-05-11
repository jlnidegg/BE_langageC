//
// Created by Jean-Louis Nidegger on 05/05/2022.
//

#ifndef BEC___MICRO_H
#define BEC___MICRO_H

#include <Arduino.h>
#include "Setup.h"
#include "Servo_motor.h"
#include "capteur_ultrason_distance.h"

/*********
 * La classe Micro gère l'obtention des bips sonores envoyés par le buzzer pour déterminer si l'argent est suffisant
*********/

class Micro : public Setup{

public:
    int Heard_money;
    long sum = 0;
    long sum_bis = 0;

    Micro(){                // Constructeur de l'objet Micro pour définir les pins et bauds adéquats
        Heard_money = 0;    // et initialiser à 0 la valeur d'argent entendue
        pin = A0; //used pin
        frequency = 115200; //Specified in Hz
        Serial.begin(frequency);
    }

    bool argentsuffisant(){     // Fonction qui détermine si le son entendu est bien un bip d'argent
        if (sum_bis>150){   // L'argent entendu est incrementé de 1 s1 l'intensité sonore est supérieure à 150
                            // (150 en valeur renvoyée par le micro, voir loop_micro)
            Heard_money += 1;
            //Serial.println(Heard_money);
        }
        if (Heard_money >= 3){ // Si on a entendu plus de 3 bip, on retourne vrai et on remet Heard_money à 0
            //Serial.println(Heard_money);
            Heard_money=0;
            //Serial.println(Heard_money);
            return true;
        }
        else{                   // Sinon, on retourne faux parce que l'argent n'est pas suffisant
            return false;
        }
        
    }

    bool loop_micro()   // Fonction de lecture de la pin micro et de conversion de l'intensité sonore reçue
    {
        for(int i=0; i<32; i++) // Donnée reçue sur 32 bits
        {
            sum += analogRead(pin); // On vient lire sur la pin l'intensité lue
        }

        sum >>= 5; // Décalage de 5 bit pour lisibilité
        sum_bis = sum;

        Serial.println(sum_bis); // Print de vérification
        //Serial.println(Heard_money);
        

        if (argentsuffisant()==true){ // Si on a payé assez d'argent, alors la condition est vraie
            return true;              // Voir intérêt dans le main
        }
        else {  // Sinon faux
            return false;
        }
        delay(10);
    }
};


#endif //BEC___MICRO_H
