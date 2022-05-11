#include <Arduino.h>
#include <Servo_motor.h>
#include <capteur_ultrason_distance.h>
#include <Motor.h>
#include <Argent.h>
#include <Micro.h>
#include <Buzzer.h>


/******
* Voici notre programme principal à embarquer sur le véhicule
******/

// Création de tout les objets pour chaque capteur/actionneur
Argent <float> A1;
//Argent <int> A2;
Buzzer Bip1;
capteur_ultrason_distance C1;
Motor M1;
Micro MI1;
Servo_motor SM1;
int Heard_money;



void setup() {  // Setup en réalité inutile puisque tout est fait dans les constructeur de classe
/**********************setup wallet**********************/
//créé par le constructeur 
/**********************setup moteur**********************/
}



void loop() { // Boucle principale du programme Arduino pour la voiture

/**********************gestion wallet**********************/
  int Max;
  Max=A1.monMax3((A1.wallet[0]/1),(A1.wallet[1]/1,05),(A1.wallet[2]/136,98));
  //Choix de la monnaie que le client possède le plus


/**********************gestion moteur**********************/
  C1.loop();
  M1.loop_motor(C1.distance); // Lancement en parallèle du reste du moteur qui se gère seul, seulement fonction des obstacles
/**********************************************************/

/**********************gestion micro**********************/
 /*if (MI1.loop_micro()==true){
   SM1.Barriere_ok = 1;
 };

if (SM1.Barriere_ok == 1){
  A1 -=3;
} */

/**********************************************************/

/**********************gestion buzzer**********************/

// On lance le buzzer uniquement lorsqu'on a la voiture proche de la barrière
if(C1.distance<7){  
  Bip1.monBip(Max);
}
// Bip retentit si le capteur ultrason repere la barrière

/**********************************************************/


/**********************gestion servo-moteur **********************/

//SM1.loop_servo();

/**********************************************************/
}
