#include <Arduino.h>
#include <Servo_motor.h>
#include <capteur_ultrason_distance.h>
#include <Motor.h>


capteur_ultrason_distance C1;
Motor M1;

void setup() {
}

void loop() {
  C1.setup();
  C1.loop();

  M1.setup();
  M1.loop_motor(C1.distance);
}
