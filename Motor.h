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
#include <capteur_ultrason_distance.h>
#define pin_relais_moteur D8


class Motor {
public:
    int Obstacle = 0; // le état bouton a 1
    void setup(){
        pinMode(pin_relais_moteur, OUTPUT);
    }

    void loop_motor(int distance){
        if (distance<6){
            Obstacle = 1;
        }
        else{
            Obstacle = 0;
        }

        if (Obstacle == 0){  // Pas d'obstacle
            //digitalWrite(relais_moteur, HIGH); // Le moteur se met à tourner
            digitalWrite(pin_relais_moteur, HIGH); //rapport cyclique a 50%
        }
        else {  // On relache le bouton poussoir
            digitalWrite(pin_relais_moteur, LOW); // Le moteur s'arrête de tourner
        }
    }
};

#endif //BEC___MOTOR_H
