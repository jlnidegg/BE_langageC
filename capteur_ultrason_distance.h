//
// Created by Jean-Louis Nidegger on 11/04/2022.
//

#ifndef BEC___CAPTEUR_ULTRASON_DISTANCE_H
#define BEC___CAPTEUR_ULTRASON_DISTANCE_H

#include <Arduino.h>

class capteur_ultrason_distance {
public:
    int PingPin = D3;
    int BaudRate = 9600;
    int distance = 0;

    void setup() {
        Serial.begin(BaudRate);

    }

    void loop() {

        pinMode(PingPin, OUTPUT);
        digitalWrite(PingPin, LOW);  // init sensor to ensure clean HIGH pulse
        delayMicroseconds(2);
        digitalWrite(PingPin, HIGH);  // make the sensor send a pulse
        delayMicroseconds(5);
        digitalWrite(PingPin, LOW);  // Set LOW again
        pinMode(PingPin, INPUT);  // Get ready to capture the duration of the resulting pulse
        // Capture how long the pin stays in HIGH state.
        unsigned long Duration = pulseIn(PingPin, HIGH);

        if (Duration == 0) {
            Serial.println("No Pulse received from the sensor");
        } else  {
            Serial.print("Distance : ");
            Serial.print(Convert_Time_Space(Duration));  // convert the duration into distance
            distance = Convert_Time_Space(Duration);
            Serial.println(" cm");
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
