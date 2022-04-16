//
// Created by Jean-Louis Nidegger on 12/04/2022.
//

#ifndef BEC___MOTOR_H
#define BEC___MOTOR_H

/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/
*********/
#include <Arduino.h>

int Obstacle = 0; // le état bouton a 1
const int relais_moteur = D8; // // le relais est connecté à la broche 1 de la carte Adruino



class Motor {
public:

    void setup(){
        pinMode(relais_moteur, OUTPUT);
    }

    void loop_motor(){
        Obstacle = 0;

        if (Obstacle == 0){  // Pas d'obstacle
            //digitalWrite(relais_moteur, HIGH); // Le moteur se met à tourner
            digitalWrite(relais_moteur, HIGH); //rapport cyclique a 50%
        }
        else {  // On relache le bouton poussoir
            digitalWrite(relais_moteur, LOW); // Le moteur s'arrête de tourner
        }
    }
};

#endif //BEC___MOTOR_H
