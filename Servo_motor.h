//
// Created by Jean-Louis Nidegger on 12/04/2022.
//

#ifndef BEC___SERVO_MOTOR_H
#define BEC___SERVO_MOTOR_H



// inclusion des bibliothèques utiles

#include <Servo.h>  // s'il s'agit d'un ESP32, il faut installer une version spéciale
// de la bibliothèque servo:
// https://github.com/RoboticsBrno/ESP32-Arduino-Servo-Library

// le servomoteur est contrôlé par les GPIO 4 de l'ESP8266
#define pinServo D6

class Servo_motor {
/**********************************************************************
   Contrôle d'un servomoteur
   https://electroniqueamateur.blogspot.com/2018/09/servomoteur-controle-par-wi-fi-esp8266.html
***********************************************************************/
    public:
    Servo monServo;  //création de l'objet servo

    void setup() {

        monServo.attach(pinServo);

        // pour affichage dans le moniteur série
        Serial.begin ( 115200 );

        Serial.println ( "Servo Moteur ready" );
    }



    void loop() {
        int laPosition;

        laPosition = 0;
        monServo.write(laPosition);
        delay(2000);

        laPosition = 180; //operating voltage 3.3 au lieu de 4.8V donc mais facteur environ 2 pour l angle
        monServo.write(laPosition);
        delay(2000);

        laPosition = -180;
        monServo.write(laPosition);
        delay(2000);
    }
};


#endif //BEC___SERVO_MOTOR_H
