//
// Created by Jean-Louis Nidegger on 11/04/2022.
//

#ifndef BEC___CAPTEUR_ULTRASON_DISTANCE_H
#define BEC___CAPTEUR_ULTRASON_DISTANCE_H

#include <Arduino.h>
#include <Setup.h>

/*********
 * La classe capteur_ultrason_distance gère la détection de la distance entre la voiture et un obstacle potentiel
*********/

class capteur_ultrason_distance : public Setup{
public:
    int distance = 0;

    capteur_ultrason_distance(){    // Conctructeur de l'objet Capteur Ultrason
        pin = D3; //used pin
        frequency = 9600; //Specified in Hz
        Serial.begin(frequency);
    }


    void loop() {

        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);  // init sensor to ensure clean HIGH pulse
        delayMicroseconds(2);
        digitalWrite(pin, HIGH);  // make the sensor send a pulse
        delayMicroseconds(5);
        digitalWrite(pin, LOW);  // Set LOW again
        pinMode(pin, INPUT);  // Get ready to capture the duration of the resulting pulse
        // Capture how long the pin stays in HIGH state.
        unsigned long Duration = pulseIn(pin, HIGH);

        if (Duration == 0) {    // Si la durée aller-retour est trop courte, cela signifie que le capteur ne renvoie pas une bonne donnée
            Serial.println("No Pulse received from the sensor");
        } else  {
            //Serial.print("Distance : ");
            //Serial.print(Convert_Time_Space(Duration)); 
            distance = Convert_Time_Space(Duration);  // convert the duration into distance
            //Serial.println(" cm");
        }
        delay (1000) ;
    }

    unsigned long Convert_Time_Space(const unsigned long fnDuration ) {
        // This function could be more precise by using floats
        // and taking into account temperature and humidity
        // I used 29 microseconds per cm.
        return fnDuration / 29 / 2 ;
    }

};

#endif //BEC___CAPTEUR_ULTRASON_DISTANCE_H
