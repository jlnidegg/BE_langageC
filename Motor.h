//
// Created by Jean-Louis Nidegger on 12/04/2022.
//

#ifndef BEC___MOTOR_H
#define BEC___MOTOR_H
#include "Setup.h"
/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/
*********/
#include <Arduino.h>

/*********
 * La classe Motor gère le contrôle du moteur DC utilisé pour la voiture
 * Sa seule fonction vérifie si un obstacle est présent devant le véhicule, mettant en marche ou non le moteur
*********/


class Motor : public Setup {

public:
    int Obstacle;

    Motor() {
        Obstacle = 0; // le état bouton a 1
        pin = D8; //used pin
        pinMode(pin, OUTPUT);
    }

    void loop_motor(int distance) {
        if (distance < 8) { // L'obstacle est proche
            Obstacle = 1;
        } else {            // L'obstacle est loin
            Obstacle = 0;
        }

        if (Obstacle == 0) {  // Pas d'obstacle
            //digitalWrite(relais_moteur, HIGH); // Le moteur se met à tourner
            digitalWrite(pin, HIGH); //rapport cyclique a 50%
        } else {  // On relache le bouton poussoir
            digitalWrite(pin, LOW); // Le moteur s'arrête de tourner
        }
    }
};

#endif //BEC___MOTOR_H