//
// Created by Jean-Louis Nidegger on 12/04/2022.
//

#ifndef BEC___SERVO_MOTOR_H
#define BEC___SERVO_MOTOR_H
#include "Argent.h"


// inclusion des bibliothèques utiles

#include <Servo.h>  // s'il s'agit d'un ESP32, il faut installer une version spéciale
// de la bibliothèque servo:
// https://github.com/RoboticsBrno/ESP32-Arduino-Servo-Library
/**********************************************************************
   Contrôle d'un servomoteur
   https://electroniqueamateur.blogspot.com/2018/09/servomoteur-controle-par-wi-fi-esp8266.html
***********************************************************************/

// le servomoteur est contrôlé par les GPIO 4 de l'ESP8266
#include <Arduino.h>
#include "Setup.h"

/*********
 * La classe Servo_motor gère l'ouverture et la fermeture de la barrière
*********/

class Servo_motor : public Setup{
public:
    int Barriere_ok = 0; // Initialement, la barrière est fermée
    int laPosition;
    int Money;
    Servo monServo;  //création de l'objet servo


    Servo_motor(){
        pin = D5; //used pin
        frequency = 115200; //Specified in Hz
        monServo.attach(pin);
        // pour affichage dans le moniteur série
        Serial.begin (frequency);
        Serial.println ( "Servo Moteur ready" );
    }

    void OpenBarriere(){
        laPosition = 0;             // Position de barrière ouverte
        monServo.write(laPosition); // Instruction d'ouverture envoyée au servo
    }

    void CloseBarriere(){
        laPosition = 180;           // Position de barrière fermée
        monServo.write(laPosition); // Instruction de fermeture envoyée au servo
    }

    void loop_servo(){
        if (Barriere_ok == 1){ // On a comptabilisé l'argent, la voiture peut passer le péage
            OpenBarriere();     // Ouverture barrière
            delay(5000);        // On attend 5 secondes afin de laisser le véhicule passer le péage
            Serial.println ( "on ouvre la barrière" );

            CloseBarriere();    // Fermeture barrière
            Barriere_ok = 0;
            delay(3000);        // Délais ajouté pour éviter les perturbations captées par le micro lorsque la barrière se ferme
        }
        else {                  // On n'a pas comptabilisé l'argent, la voiture ne peut pas passer le péage
            CloseBarriere();
        }
    }

};


#endif //BEC___SERVO_MOTOR_H