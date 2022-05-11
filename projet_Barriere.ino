#include <Arduino.h>
#include <Servo_motor.h>
#include <capteur_ultrason_distance.h>
#include <Motor.h>
#include <Argent.h>
#include <Micro.h>
#include <Buzzer.h>

/******
* Voici notre programme principal à embarquer sur la barrière
******/

// Création de tout les objets pour chaque capteur/actionneur
Argent <float> A1;
//Argent <int> A2;
Buzzer Bip1;
capteur_ultrason_distance C1;
Motor M1;
Micro MI1;
Servo_motor SM1;
//int Heard_money;

void setup() {  // Setup en réalité inutile puisque tout est fait dans les constructeur de classe
/**********************setup wallet**********************/
//créé par le constructeur 
/**********************setup moteur**********************/
}

void loop() { //Boucle principale du programme Arduino pour la barrière

/**********************gestion wallet**********************/
  int Max;
  Max=A1.monMax3((A1.wallet[0]/1),(A1.wallet[1]/1,05),(A1.wallet[2]/136,98));
  //Choix de la monnaie que le client possède le plus


/**********************gestion moteur**********************/
  /*C1.loop();
  M1.loop_motor(C1.distance);*/
/**********************************************************/

/**********************gestion micro**********************/

// Si la loop_micro détecte que l'argent a été payé, alors la barrière peut s'ouvrir (passage de Barriere_ok à 1)
 if (MI1.loop_micro()==true){
   SM1.Barriere_ok = 1;
 };

if (SM1.Barriere_ok == 1){ // Aussi, si Barriere_ok est à 1, alors on enlève l'argent du portfeuille
  A1 -=3;
} 

/**********************************************************/

/**********************gestion buzzer**********************/
/*if(C1.distance<7){  
  Bip1.monBip(Max);
}*/
// Bip retentit si le capteur ultrason repere la barrière

/**********************************************************/


/**********************gestion servo-moteur **********************/

SM1.loop_servo(); // Lancement du servo_motor qui se gère en parallèle du reste en vérifiant la valeur de barriere_ok en permanence

/**********************************************************/
}
