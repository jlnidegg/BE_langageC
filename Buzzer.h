//
// Created by Jean-Louis Nidegger on 05/05/2022.
//

#ifndef BEC___BUZZER_H
#define BEC___BUZZER_H

#include <Arduino.h>
#include "Setup.h"

/*********
 * La classe Buzzer gère l'envoie des bips pour indiquer l'argent disponible
*********/

class Buzzer : public Setup{
public:
    int timeOn=100; //specified in milliseconds
    int timeOff=1000; //specified in millisecods
    int bipfrequency;

    Buzzer(){       // Constructeur de l'objet Buzzer
        pin = D7; //used pin
        bipfrequency = 1000; //Specified in Hz
    }

    void setup() {
        // put your setup code here, to run once:

    }

    void monBip(int B) {    // En argument l'argent à convertir en bip
        if (B >= 3) {       // Si on a plus que ce qu'il faut pour payer
            for (int i = 0; i < 3; i++) { // Alors on envoie les 3 bips nécessaires
                tone(pin, bipfrequency); // Allumage buzzer
                delay(timeOn);           // Temps allumé
                noTone(pin);             // Mise hors tension buzzer
                delay(timeOff);          // Temps éteint
            }
        }
        else {
            for (int i = 0; i < B; i++) { // Sinon on envoie un nombre de bips équivalent à notre argent (ici compris en 0 et 2)
                tone(pin, bipfrequency);
                delay(timeOn);
                noTone(pin);
                delay(timeOff);
            }
        }
    }
};


#endif //BEC___BUZZER_H